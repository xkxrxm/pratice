#include<iostream>
using namespace std;

class Useless
{
private:
    int n;
    char *pc;
    static int ct;
public:
    Useless(/* args */);
    explicit Useless(int k);
    Useless(const Useless & other);
    Useless(Useless && other);
    Useless operator+(const Useless & other) const; // 常量成员函数，常量成员函数承诺不会修改对象的状态（即不会修改任何非 mutable 的成员变量）。这使得代码更安全，易于理解。
    ~Useless();
    void ShowObject() const;
};

Useless u_double(const Useless & other);

int Useless::ct = 0;

Useless::Useless(/* args */)
{
    ct++;
    n = 0;
    pc = nullptr;
}

Useless::Useless(int k){
    n = k;
    pc = new char[n];
    ct++;
}

Useless::Useless(const Useless & other){
    ct++;
    n = other.n;
    pc = new char[n];
    for(int i = 0; i < n; i++)
        pc[i] = other.pc[i];
}

Useless::Useless(Useless && other){
    ct++;
    n = other.n;
    pc = other.pc;
    other.n = 0;
    other.pc = nullptr;
}

Useless Useless::operator+(const Useless & other) const{
    Useless temp;
    temp.n = n + other.n;
    temp.pc = new char[temp.n];
    for(int i = 0; i < n; i++)
        temp.pc[i] = pc[i];
    for(int i = n; i < temp.n; i++)
        temp.pc[i] = other.pc[i - n];
    return temp;
}

Useless::~Useless()
{
    ct--;
    delete[] pc;
}

Useless u_double(const Useless & other){
    return other + other;
}


void Useless::ShowObject() const{
    cout << "Object: " << this << "  "; 
    cout << "n = " << n << "  ";
    cout << "ct = " << ct << endl;
}
int main(){
    Useless a(3);
    Useless b(a); // copy constructo
    Useless c(a + b); // move constructor
    Useless d(Useless(1) + Useless(2)); // move constructo
    a.ShowObject();
    b.ShowObject();
    c.ShowObject();
    d.ShowObject();
    Useless e = Useless(move(a)); // move assignment
    e.ShowObject();
    a.ShowObject();
    Useless f = u_double(a); // move constructor
    f.ShowObject();
    // Useless g = u_double(2);  // error explicit 避免了隐式转换
    // Useless h = 29; // error explicit 避免了隐式转换
    return 0;
}
