#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main(){

    double a ;
    cout << "&a= " << &a << endl;
    a=2.0;
    cout << "&a= " << &a << endl;
    a=5.0;
    cout << "&a= " << &a << endl;
    return 0;
}