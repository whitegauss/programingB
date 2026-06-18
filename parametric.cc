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
double pi=4*atan(1.0);
double x,y,z,r,R;

ofstream fout;

fout.open("kakko1.data");
for(int i =0; i<100000; i++){
    double t = 2.0 * i * pi / 100000.0;
    x=16* pow(sin(t),3.0);
    y=13*cos(t)-5*cos(2*t)-2*cos(3*t)-cos(4*t);
    fout << x << " " << y << "\n";
};
fout.close();

fout.open("kakko2.data");
for(int j=0; j<100000;j++ ){
    double theta=2.0 * j * pi / 100000.0;
    r=abs(sin(5*theta/2))+0.6+0.1*log(abs(sin((5*theta-pi)/2))+0.05);
    x=r*cos(theta);
    y=r*sin(theta);
    fout << x << " " << y << "\n";
};
fout.close();

fout.open("kakko3.data");
R = 3.0; 
r = 1.0; 
for(int k = 0; k < 100000; k++) {
    int i_theta = k % 100;    
    int i_phi   = k / 100;    
    
    double theta = 2.0 * i_theta * pi / 100.0;
    double phi   = 2.0 * i_phi   * pi / 1000.0;
    
    x = (R + r * cos(theta)) * cos(phi);
    y = (R + r * cos(theta)) * sin(phi);
    z = r * sin(theta);
    
    fout << x << " " << y << " " << z << "\n";
};
fout.close();

}