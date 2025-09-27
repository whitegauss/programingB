#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

void calculate_products(const int* v1, const int* v2, int* v3, int* v4);

int main() {
    int a[3] = {1, 2, 3};
    int b[3] = {3, 2, 1};

    int c;         
    int d[3]; 

    calculate_products(a, b, &c, d);
    cout << "v1= (" << a[0] << ", " << a[1] << ", " << a[2] << ")" << endl;
    cout << "v2= (" << b[0] << ", " << b[1] << ", " << b[2] << ")" << endl;
    cout << "inner product= " << c << endl;
    cout << "cross product= (" << d[0] << ", " << d[1] << ", "  << d[2] << ")" << endl;
    return 0;
}

void calculate_products(const int* v1, const int* v2, int* v3, int* v4) {

    *v3 = (v1[0] * v2[0]) + (v1[1] * v2[1]) + (v1[2] * v2[2]);

    v4[0] = v1[1] * v2[2] - v1[2] * v2[1];
    v4[1] = v1[2] * v2[0] - v1[0] * v2[2];
    v4[2] = v1[0] * v2[1] - v1[1] * v2[0];

}