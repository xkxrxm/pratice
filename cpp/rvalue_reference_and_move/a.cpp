#include<iostream>
using namespace std;

double up(double x)
{
    return 2.0 * x;
}

void r1(const double &rx)
{
    cout << "r1: " << rx << endl;
}

void r2(double &rx)
{
    cout << "r2: " << rx << endl;
}

void r3(double &&rx)
{
    cout << "r3: " << rx << endl;
}

int main()
{
    double x = 3.0;
    r1(x);
    r1(x+1);
    r1(up(x));
    r2(x);
    // r2(x+1); // 错误，x+1是右值
    // r2(up(x)); // 错误，up(x)是右值
    // r3(x); // 错误，x是左值
    r3(x+1);
    r3(up(x));
}