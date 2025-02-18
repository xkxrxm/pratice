# include <iostream>
using namespace std;

void change(const int *p, int add){
    // *p += add; // error
    int *pp = const_cast<int *>(p);
    *pp += add;
}
void change(const int& p, int add){
    // p += add; // error
    int &pp = const_cast<int&>(p);
    pp += add;
}
int main() {
    const int a = 10;
    int *p = const_cast<int *>(&a);
    *p = 20;
    cout << a << endl;
    cout << *p << endl;

    int b = 10;
    change(&b, 10);
    change(&a, 10);
    cout << a << endl;
    cout << b << endl;

    change(b, 10);
    change(a, 10);
    cout << a << endl;
    cout << b << endl;
    return 0;
}