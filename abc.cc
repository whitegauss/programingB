#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "integer 1/3= " << int(1/3) << endl;
    cout << "float 1/3= " << setprecision(18) << float(1)/3 << endl;
    cout << "double 1/3= " << setprecision(18) << double(1)/3 << endl;
    return 0;
}
