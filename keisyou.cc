#include <iostream> //class02.cc
#include <string>
using namespace std;

class Person{
private:
 string name;
int age;
public:
 Person(string s, int n);//初期化を行うコンストラクタの宣言（クラスと同じ名前）
 void disp();
};
Person::Person(string s, int n){
 name = s;
if(n<0) age = 0;else age = n;
}
void Person::disp()
{
 cout << "名前=" << name << " 年齢=" << age << '\n';
}

int main()
{
 Person dt("鈴木五郎", 55);//初期化する
 dt.disp();//初期化の内容を見る
}
