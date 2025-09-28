#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

class Vector{
protected:
    double x, y, z;
public:
    Vector(double a, double b, double c);
    void disp() const;
};

Vector::Vector(double a, double b, double c) {
    x = a; 
    y = b; 
    z = c;
}

void Vector::disp() const {
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}

class Vector3d : public Vector {
public:
    Vector3d(double a, double b, double c) : Vector(a, b, c) {}
    
    Vector3d cross(const Vector3d& v) const; 

    double dot(const Vector3d& v) const {
        return x*v.x + y*v.y + z*v.z;
    }
};

Vector3d Vector3d::cross(const Vector3d& v) const {
    return Vector3d(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}


int main() {
    Vector3d v1(2, 3, 4);
    Vector3d v2(4, 3, 2);
    
    cout << "v1= ";
    v1.disp();
    cout << "v2= ";
    v2.disp();

    double p = v1.dot(v2);
    cout << "v1 * v2 = " << p << endl;

    Vector3d v3 = v1.cross(v2);
    cout << "v1 x v2 = ";
    v3.disp();
    
    return 0;
}