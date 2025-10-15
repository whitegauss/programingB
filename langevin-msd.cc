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
    int N=pow(10,4);
    double Pi=4*atan(1.0),X=0.0,Y=0.0;
    double K_BT=1,m=1,zeta=2;
    vector<double> msd(N, 0.0);
    double DT=0.0001,dw,x=0,v=0;
    double D=K_BT*zeta;

    fstream fout("msd.txt", ios::out | ios::trunc);

    for (int j=0;j<100;j++) {
        x=0.0,v=0.0;
        for(int i=0;i<N;i++){
            do {
                X = (double)rand() / RAND_MAX;
            } while (X == 0.0);
            Y=(double)rand()/RAND_MAX;
            dw=sqrt(-2*log(X))*sqrt(2.0*DT*D)*cos(2*Pi*Y);
            v=v-zeta*v*DT/m+dw/m;
            x=x+v*DT;
            if(j==0){
                msd[i] = pow(x,2);
            }else{
                msd[i] = msd[i]+pow(x,2);
            }
        }
    }

    for (int i=0; i<N; i++) {
    double time = i * DT;
    double average_msd = msd[i] / 100; 
    fout << time << " " << average_msd << endl;
    }
 fout.close(); 
   return 0;
}