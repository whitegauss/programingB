#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

int main(){

    int n;
    double pi2= atan(1.0)*8;
    double d,x,y;

    ifstream fin;
    fin.open("b01_1_file.data");
    fin >> n;
    fin.close();

    cout << "n=" << n << endl;
    d=pi2/2;

    ofstream fout;
    fout.open("b01_1_file.data");
    fout <<setprecision(16) << fixed << right;

    for(int i=0 ; i<=n ;i++){
        x=i*d;y=sin(x);
        fout << setw(12) << x <<setw(12) << y <<endl;
    }

    fout.close();

}