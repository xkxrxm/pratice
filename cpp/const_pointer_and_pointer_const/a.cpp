#include<iostream>
using namespace std;
int main(){
    int a = 10;
    int b = 20;
    int *const p = &a; // p 是一个常量指针，指向的地址不能改变，但是指针指向的值可以改变
    *p = 100;
    // p = &b; // error
    const int *q = &a; // q 是一个指针常量，指向的地址可以改变，但是指针指向的值不能改变
    // *q = 100; // error
    q = &b; // ok
    cout << a << endl;
    cout << b << endl;
    return 0;

}