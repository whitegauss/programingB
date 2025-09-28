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
    
    int n1,n2,n3,n4,n5,n6;  
    n1=n2=n3=n4=n5=n6=0;
    for (int i=0; i<100; i++){
        double x=(double)rand()/RAND_MAX;

        if(0<=x && x<1.0/6.0) {  
            n1=n1+1;
        }
        else if(1.0/6.0<=x && x<2.0/6.0) n2=n2+1;
        else if(2.0/6.0<=x && x<3.0/6.0) n3=n3+1;
        else if(3.0/6.0<=x && x<4.0/6.0) n4=n4+1;
        else if(4.0/6.0<=x && x<5.0/6.0) n5=n5+1;
        else n6++;

    }
        cout<<1<<" "<<n1/100.0 <<endl;
        cout<<2<<" "<<n2/100.0<<endl;
        cout<<3<<" "<<n3/100.0<<endl;
        cout<<4<<" "<<n4/100.0<<endl;
        cout<<5<<" "<<n5/100.0<<endl;
        cout<<6<<" "<<n6/100.0<<endl;
        return 0;
}