#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
    const int N_bins = 1000;        // 区間の分割数
    const int N_iter = 1000000;     // 反復回数 (10^6)
    const double dx = 1.0 / N_bins; // 各区間の幅
    
    vector<int> histogram(N_bins, 0); // ヒストグラム
    
    double x = 0.1; // 初期値
    
    // 過渡状態を捨てる
    for(int i = 0; i < 1000; i++){
        x = 4.0 * x * (1.0 - x);
    }
    
    // 本計算
    for(int n = 0; n < N_iter; n++){
        x = 4.0 * x * (1.0 - x);
        
        int bin = (int)(x / dx);
        if(bin >= N_bins) bin = N_bins - 1;
        if(bin < 0) bin = 0;
        
        histogram[bin]++;
    }
    
    // 出力設定
    for(int i = 0; i < N_bins; i++){
        double x_center = (i + 0.5) * dx;
        double rho = (double)histogram[i] / (N_iter * dx);
        
        // x_centerとrhoを固定小数点(fixed)で出力
        cout << fixed << setprecision(6) << x_center << " " << rho << endl;
    }
    
    return 0;
}