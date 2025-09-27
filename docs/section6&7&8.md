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