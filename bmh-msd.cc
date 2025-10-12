#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    int N=pow(10,6);
    double Pi=4*atan(1.0),X,Y;
    double z[N],DT=0.01,dw,x,y;
    int D=1,k=2;
    x=0.,y=0.;

    fstream fout("bmh-msd.txt");
    for(int j=0;j<N;j++) {
    for (int i=0;i<N;i++){
    while (X == 0.0) {
        X = (double)rand() / RAND_MAX;
    }
    Y=(double)rand()/RAND_MAX;
    dw=sqrt(-2*log(X))*sin(2*Pi*Y)*sqrt(2*D*DT);
    x = x - k * x * DT + dw;

    double msd[i]= pow(x,2);


    }
    fout <<  << " " << x << endl;
}
   fout.close(); 
   return 0;
}