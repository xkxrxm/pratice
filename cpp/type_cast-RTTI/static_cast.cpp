#include <iostream>

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void show() {
        std::cout << "Derived class" << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived();
    Derived* derivedPtr = static_cast<Derived*>(basePtr);
    derivedPtr->show();

    int a = 10;
    double b = static_cast<double>(a);
    std::cout << "Converted value: " << b << std::endl;

    delete basePtr;
    return 0;
}