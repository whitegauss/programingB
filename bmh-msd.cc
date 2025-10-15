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
    srand(time(NULL));
    int N=10000;
    double Pi=4*atan(1.0),X=0.0,Y=0.0;
    vector<double> msd(N, 0.0);
    double DT=0.001,dw,x;
    double  D=1.0,k=2.0;
    x=0.;
    
    fstream fout("msd.txt", ios::out | ios::trunc);


    for(int j=0;j<100;j++) {
        x=0.0;
        for (int i=0;i<N;i++){
            do {
                X = (double)rand() / RAND_MAX;
            } while (X == 0.0);
            Y = (double)rand() / RAND_MAX;
            dw = sqrt(-2.0*log(X)) * cos(2.0*Pi*Y) * sqrt(2.0*D*DT);
            x = x - k * x * DT + dw;
            if(j!=0){
            msd[i] = msd[i]+pow(x,2);
            }else{
            msd[i] = pow(x,2);
            }
        }
    }
    for (int i=0; i<N; i++) {
    double time = i * DT;
    double average_msd = msd[i] / 100.0; 
    fout << time << " " << average_msd << endl;
}
   fout.close(); 
   return 0;
}
