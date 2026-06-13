#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

struct Vector3 {
        int x, y, z;
    };

Vector3 set(double x, double y, double z) {
    Vector3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

Vector3 add(Vector3 v1, Vector3 v2) {
    Vector3 added;
    added.x = v1.x + v2.x;
    added.y = v1.y + v2.y;
    added.z = v1.z + v2.z;
    return added;
}

Vector3 sub(Vector3 v1, Vector3 v2) {
    Vector3 subed;
    subed.x = v1.x - v2.x;
    subed.y = v1.y - v2.y;
    subed.z = v1.z - v2.z;
    return subed;
}

int inner_product(Vector3 v1, Vector3 v2) {
    int inner;
    inner=v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
    return inner;
}

Vector3 cross_product(Vector3 v1, Vector3 v2) {
    Vector3 cross;
    cross.x = v1.y * v2.z - v1.z * v2.y;
    cross.y = v1.z * v2.x - v1.x * v2.z;
    cross.z = v1.x * v2.y - v1.y * v2.x;
    return cross;
}

Vector3 scale(Vector3 v, double s) {
    Vector3 scale;
    scale.x = v.x * s;
    scale.y = v.y * s;
    scale.z = v.z * s;
    return scale;
}

void show(Vector3 v) {
    cout << "(" << v.x << ", " << v.y << ", " << v.z << ")" << endl;
}

int main(){
    Vector3 v1, v2, add2, sub2, cross2, scale2;
    int n;
    v1=set(3,4,5);
    v2=set(3,2,1);
    add2=add(v1,v2);
    sub2=sub(v1,v2);
    n=inner_product(v1,v2);
    cross2=cross_product(v1,v2);
    scale2=scale(v1,2.0);
    cout << "v1="; show(v1);
    cout << "v2="; show(v2);
    cout << "v1+v2="; show(add2);   
    cout << "v1-v2="; show(sub2);
    cout << "v1*v2=" << n << endl;
    cout << "v1xv2="; show(cross2);
    cout << "2.0*v1="; show(scale2);
}