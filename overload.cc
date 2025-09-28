#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

class Vector{
public:
    double x,y,z;
public:
    Vector(double a, double b, double c){
        x=a; y=b; z=c;
    }
    void disp();
    void set(double a, double b, double c){
    x=a; y=b; z=c;
}
};

void Vector::disp(){
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}

Vector operator * (const Vector& v1, double a){
    return Vector(v1.x*a, v1.y*a, v1.z*a);
}

Vector operator ^ (const Vector& v1, const Vector& v2){
    return Vector(v1.y*v2.z - v1.z*v2.y,
                  v1.z*v2.x - v1.x*v2.z,
                  v1.x*v2.y - v1.y*v2.x);
}

int main(){
    Vector v1(3,4,5), v2(3,2,1);
    cout << "v1= ";
    v1.disp();
    cout << "v2= ";
    v2.disp();

    Vector v3 = v1 ^ v2;
    cout << "v1 x v2= ";
    v3.disp();
    Vector v4 = v1 * 2.0;
    cout << " 2.0*v1= ";
    v4.disp();
    return 0;
}