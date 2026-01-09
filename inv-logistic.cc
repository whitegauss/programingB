#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

int main(){
    const int N_bins = 1000;        // 区間の分割数
    const int N_iter = 1000000;     // 反復回数 (10^6)
    const double dx = 1.0 / N_bins; // 各区間の幅
    
    vector<int> histogram(N_bins, 0); // ヒストグラム（頻度）
    
    // 初期値（0と1以外の値）
    double x = 0.1;
    
    // 最初の1000回は過渡状態を捨てる
    for(int i = 0; i < 1000; i++){
        x = 4.0 * x * (1.0 - x);
    }
    
    // ロジスティック写像の反復とヒストグラム作成
    for(int n = 0; n < N_iter; n++){
        x = 4.0 * x * (1.0 - x);
        
        // xが入る区間のインデックスを計算
        int bin = (int)(x / dx);
        
        // 境界処理（x=1.0の場合）
        if(bin >= N_bins) bin = N_bins - 1;
        if(bin < 0) bin = 0;
        
        histogram[bin]++;
    }
    
    // 確率密度関数に規格化して出力
    // 規格化条件: ∫ρ(x)dx = 1  →  Σρ(x_i)*dx = 1
    // よって ρ(x_i) = histogram[i] / (N_iter * dx)
    
    cout << scientific << setprecision(6);
    
    for(int i = 0; i < N_bins; i++){
        double x_center = (i + 0.5) * dx;  // 区間の中心位置
        double rho = (double)histogram[i] / (N_iter * dx);  // 確率密度関数
        cout << x_center << " " << rho << endl;
    }
    
    return 0;
}