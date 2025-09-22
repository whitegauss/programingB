#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

int main(){
    double x,y,z;


ofstream fout;
fout.open("fxy.data");

for (int j=0 ; j<=40; j++){
    y=-2.0+0.1*j;
    for (int i=0 ; i<=40; i++){
        x=-2.0+0.1*i;
        z=exp(x*x+y*y);
        fout<<setprecision(16)<<x<<" "<<y<<" "<<z<<endl;
    }
    fout<<endl;
}

fout.close();
return 0;

}