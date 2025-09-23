#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
 
    int c[4]={0,1,2,3};

    cout << "c="    << c << endl;
    cout << "&c[0]=" << &c[0] << endl;
    cout << "c[0]=" << c[0] << endl;

    int *q;
    q  = c;

    cout << "c[0]+c[3]=" << *q + *(q+3) << endl;



    int *p;
    p  = &c[0];
    cout << "p+1=" << p+1 << endl;

}