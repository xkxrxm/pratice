## 问题
1. 什么是右值，右值和左值的区别
2. 什么是常量成员函数，如何定义声明常量成员函数
3. explicit关键字的作用及用法，隐形类型转换有哪些场景

## 答案
1. 右值包括字面常量（C-风格的字符串除外，它表示地址）、诸如x+y等**表达式**以及返回**值**的函数（条件是该函数返回的不是引用）。
```c++
// 这些是左值引用,相当于给变量起别名
int n;
int * pt = new int;
const int b = 101
int & rn = n; 
int & rt = *pt;
const int & rb = b;

// 这些是右值引用
int x = 10;
int y = 23;
int && r1 = 13;
int && r2 = x+y;
double && r3 = std::sqrt(2.0);
```
2. 当你在类的成员函数声明后加上 const 关键字时，这个函数被称为 **常量成员函数**（const member function）。常量成员函数的主要作用是保证该函数不会修改类的成员变量。
```cpp
class MyClass {
public:
    int getValue() const { return value; } // 常量成员函数
    void setValue(int v) { value = v; }    // 非常量成员函数
private:
    int value;
};
```
3. explicit 关键字用于修饰构造函数和转换运算符，以防止隐式类型转换。它的主要作用是避免编译器在不明确的情况下自动进行类型转换。
```cpp
class MyClass {
public:
    explicit MyClass(int value) { /* ... */ }
};

void func(MyClass obj) { /* ... */ }

int main() {
    func(10); // 错误：不能将 int 隐式转换为 MyClass
    MyClass a = 10; // 错误：不能将 int 隐式转换为 MyClass
    MyClass obj(10); // 正确：显式构造
    func(obj); // 正确
}
```