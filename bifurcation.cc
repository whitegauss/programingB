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
    double x;

    fstream fout("msd.txt", ios::out | ios::trunc);
    for(int j=0;j<10;j++) {
        double X = (double)rand() / RAND_MAX;
        for(double a=0;a<=200;a++) {
            double b=2.0+a/100.0;
            x=X;
            for(int i=0;i<=100;i++) {
               x=b*x*(1-x);
               if(i==100){
                fout<<b<<" "<<x<<endl;
               }
                }
            }
    }
    fout.close();
    return 0;
}