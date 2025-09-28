# オーバーロード（多重定義）
## 課題

- [第8回課題](../overload.cc)

## 概要
c++では同じ演算子に対し、複数の意味を満たせることができる。例えば+演算子はただ数値を足すだけでなく、文字列を連結したり、配列を結合したりすることもできる。これをオーバーロード（多重定義）と呼ぶ。今回はベクトルの計算を例にオーバーロードを説明する。
例として、3次元ベクトルを表すクラスVector3dを考える。x,y,zの3つの成分を持ち、ベクトルの和、内積、外積を計算できるとする。
```cpp
class Vector3d {
protected:
    double x,y,z;
public:
    Vector3d(double a, double b, double c);
    void disp();
    Vector3d operator+(const Vector3d& v) const; // ベクトルの和
    double operator*(const Vector3d& v) const; // ベクトルの内積
    Vector3d operator^(const Vector3d& v) const; // ベクトルの外積
};

Vector3d::Vector3d(double a, double b, double c)  {  // ← クラス内でコンストラクタを定義
    x=a; y=b; z=c;
}
void Vector3d::disp() {  // ← クラス内でメンバ関数を定義
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}
Vector3d Vector3d::operator+(const Vector3d& v) { // ベクトルの和
    return Vector3d(x + v.x, y + v.y, z + v.z);
}
double Vector3d::operator*(const Vector3d& v) const {
    return x*v.x + y*v.y + z*v.z;
}
Vector3d Vector3d::operator^(const Vector3d& v) const {
    return Vector3d(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}
// 使う側のコード
int main() {
    Vector3d v1(1, 0, 0);
    Vector3d v2(0, 1, 0);
    Vector3d v3 = v1 ^ v2; // cross()呼び出しよりスッキリ！
    v3.disp(); // (0, 1, 0) と表示される
}
```

クラスで書くより汎用性があり、わかりやすいコードになる。