#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
int n=1e5;
int i;
double pi=4*atan(1.0);
double d=2*pi/n;
double x;

double sum=0.0;
for (i=0;i<=n-1;i++){
    if(i==0){
     sum=sum+1*d;
    }else{
        x=d*i;
        sum= sum + sin(x)/x*d;
    }
}
cout<<setprecision(6)<<sum<<endl;
return 0;
}