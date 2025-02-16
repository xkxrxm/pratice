#include <iostream>
#include <string>
using namespace std;
class Cpmv
{
public:
    struct Info
    {
        string qcode;
        string zcode;
    };
    
private:
    Info *pi;
public:
    Cpmv(){
        pi = nullptr;
        cout << "Cpmv()\n";
    };
    Cpmv(std::string q, std::string z){
        cout << "Cpmv(std::string q, std::string z)\n";
        pi = new Info;
        pi->qcode = q;
        pi->zcode = z;
    }
    Cpmv(const Cpmv &cp){
        cout << "Cpmv(const Cpmv &cp)\n";
        pi = new Info;
        pi->qcode = cp.pi->qcode;
        pi->zcode = cp.pi->zcode;
    }

    Cpmv(Cpmv &&cp){
        cout << "Cpmv(Cpmv &&cp)\n";
        pi = cp.pi;
        cp.pi = nullptr;
    }

    ~Cpmv(){
        cout << "~Cpmv()\n";
        delete pi;
    }

    Cpmv & operator=(const Cpmv &cp){
        cout << "Cpmv & operator=(const Cpmv &cp)\n";
        if (this == &cp) return *this;
        delete pi;
        if(cp.pi==nullptr){
            pi = nullptr;
            return *this;
        }
        pi = new Info;
        pi->qcode = cp.pi->qcode;
        pi->zcode = cp.pi->zcode;
        return *this;
    }

    Cpmv & operator=(Cpmv &&cp){
        cout << "Cpmv & operator=(Cpmv &&cp)\n";
        if (this == &cp) return *this;
        delete pi;
        pi = cp.pi;
        cp.pi = nullptr;
        return *this;
    }

    Cpmv operator+(const Cpmv &cp) const{
        cout << "Cpmv operator+(const Cpmv &cp) const\n";
        // 空指针检查
        if (!pi || !cp.pi) {
            cerr << "Error: Attempting to add objects with null pi pointers\n";
            return Cpmv(); // 返回空对象
        }
        return Cpmv(pi->qcode + cp.pi->qcode, pi->zcode + cp.pi->zcode);
    }

    void Display() const{
        if (pi == nullptr){
            cout << "pi is nullptr\n";
            return;
        }
        cout << pi->qcode << " " << pi->zcode << endl;
    }
};

int main(){
    Cpmv c1("q1", "z1");
    Cpmv c2("q2", "z2");
    Cpmv c3 = c1 + c2; // 这里经过编译器返回值优化，不会调用移动构造函数
    c3.Display();
    Cpmv c4 = std::move(c3); // 移动构造函数
    c4.Display();
    c3.Display();
    Cpmv c5 = c4; // 拷贝构造函数
    c5.Display();
    c4.Display();
    c5 = std::move(c4); // 移动赋值函数
    c5 = c3; // 拷贝赋值函数
    c5.Display();
    c4.Display();
}

