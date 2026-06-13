#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
int n,i;
cout<< "input n =";
cin>>n;
cout << "\n"<<"n="<<n<<endl;

double x[n+1],y[n+1];
const double pi=4*atan(1.0);
if(n<=8){
cout<<setprecision(16)<<pi<<endl;
}
double d=pi/n;
for(i=0;i<=n;i++){
x[i]=d*i;
y[i]=sin(x[i]);
}

if (n<=8){
for(i=0;i<=n;i++){
cout <<"x,y="<<fixed<<setprecision(6)<<x[i]<<" "<<y[i]<<endl;
}}
double s=(y[0]+y[n])/2;
for(i=1;i<=n-1;i++){
s=s+y[i];}
s=s*d;
cout<<"n="<<n<<" s="<<setprecision(6)<<s<<endl;


}