# 構造体、クラス
## 課題
- [第6回課題(提出不要)](../kadai6.cc)
- [第7回課題](../kadai7.cc)
- [第8回課題](../kadai8.cc)

## 構造体
構造体は複数のデータをまとめて一つのデータとして扱うための仕組み。
例えば、3次元ベクトルを表すためにx, y, zの3つの変数を使う場合、構造体を使用しない場合、
```cpp
double x1, y1, z1; // ベクトル1
double x2, y2, z2; // ベクトル2
```
のように個別に変数を定義する必要があり、管理が煩雑になる。構造体を使うと、以下のようにまとめて定義できる。    
```cpp
struct Vector3 {
    double x,y,z;
};
```

## クラス
クラスは構造体に加えて、データとそれに関連する関数（メソッド）をまとめて定義できる。  
例えば、3次元ベクトルの内積や外積を計算するメソッドをクラスに含めることができる。  
```cpp
class Vector3 {
public:
    double x,y,z;   
    Vector3(double x, double y, double z) : x(x), y(y), z(z) {} // コンストラクタ
    double dot(const Vector3& other) { // 内積
        return x * other.x + y * other.y + z * other.z;
    }
    Vector3 cross(const Vector3& other) { // 外積
        return Vector3(y * other.z - z * other.y,
                       z * other.x - x * other.z,
                       x * other.y - y * other.x);
    }
};
```
数値計算やゲームの処理などでよく使われる。

## カプセル化
クラスはデータとメソッドを一つにまとめることで、データの整合性を保ちやすくする。  
例えば、ベクトルの大きさを変更するメソッドをクラス内に定義し、外部から直接データを変更できないようにすることで、不正な状態を防ぐことができる。

## コンストラクタ
コンストラクタはクラスのインスタンス（オブジェクト）を生成するさい、初期化に使われる特別なメソッド。
デストラクタはオブジェクトが破棄されるときに呼ばれるメソッドで、リソースの解放などに使われる。（どうしても高度なシミュレーションでは重くなってしまうのでメモリ管理はC++を学ぶ意義の一つの大きなところだと思います。）

## 継承
クラスは他のクラスを継承して、新しいクラスを作成できる。  
例えば、3次元ベクトルクラスを継承して、4次元ベクトルクラスを作成することができる。  
```cpp
class Vector4 : public Vector3 {
public:
    double w;
    Vector4(double x, double y, double z, double w) : Vector3(x, y, z), w(w) {}
};
``` 

## 分割コンパイル
関数やクラスを複数のファイルに分割して定義し、必要な部分だけをコンパイルすることができる。  
例えば、ベクトルクラスをvector.hとvector.cppに分割し、main.cppで使用する場合、以下のように記述する。  
```cpp
// vector.h
#ifndef VECTOR_H
#define VECTOR_H
class Vector3 {
public:
    double x,y,z;  
    Vector3(double x, double y, double z);
    double dot(const Vector3& other);
    Vector3 cross(const Vector3& other);
};
#endif  
```
```cpp
// vector.cpp
#include "vector.h"
Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
double Vector3::dot(const Vector3& other) {
    return x * other.x + y * other.y + z * other.z;
}
Vector3 Vector3::cross(const Vector3& other) {
    return Vector3(y * other.z - z * other.y,
                   z * other.x - x * other.z,
                   x * other.y - y * other.x);
}
```
```cpp
// main.cpp
#include <iostream>
#include "vector.h" 
using namespace std;
int main() {
    Vector3 v1(1.0, 2.0, 3.0);
    Vector3 v2(4.0, 5.0, 6.0);
    cout << "Dot product: " << v1.dot(v2) << endl;
    Vector3 v3 = v1.cross(v2);
    cout << "Cross product: (" << v3.x << ", " << v3.y << ", " << v3.z << ")" << endl;
    return 0;
}
```
コンパイルは以下のように行う。
```bash
g++ -o main main.cpp vector.cpp
```
このように分割することで、コードの再利用性が高まり、管理が容易になる。（授業で行われる例であればそこまで大きくないが、実際の開発では数千行に及ぶこともあるため、分割コンパイルは非常に重要な技術となる。）
