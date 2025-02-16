## 问题
1. 什么是右值，右值和左值的区别
2. 什么是常量成员函数，如何定义声明常量成员函数
3. explicit关键字的作用及用法，隐形类型转换有哪些场景
4. 移动构造函数，拷贝构造函数，移动赋值函数，拷贝赋值函数的实现，什么情况下会调用什么函数
## 答案
1. 右值包括字面常量（C-风格的字符串除外，它表示地址）、诸如x+y等**表达式**以及返回**值**的函数（条件是该函数返回的不是引用）。
可以出现在表达式左边的是左值，不可以出现在左边的是右值
可以取地址操作的是左值，不可以取地址操作的是右值

左值引用只可以关联到左值，右值引用只可以关联到右值，常量左值引用既可以关联左值又可以关联右值
```c++
// 这些是左值引用
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
4. 见c.cpp,要注意的时，编译器返回值优化会优化掉临时对象的创建，像 ` Cpmv c = a+b `本来会先创建临时对象，然后再调用移动构造函数，可是经过编译器（RVO返回值优化），不会调用移动构造函数，关闭优化（`-fno-elide-constructors`）后可以看到调用了。
