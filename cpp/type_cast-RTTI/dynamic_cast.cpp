#include <iostream>
#include <typeinfo>

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
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    if (derivedPtr) {
        derivedPtr->show();
    } else {
        std::cout << "Conversion failed" << std::endl;
    }

    delete basePtr;
    return 0;
}