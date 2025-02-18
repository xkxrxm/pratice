#include <iostream>
#include <typeinfo>
#include <cassert>

class Base
{
public:
    virtual ~Base() {} // 必须有虚函数以启用 RTTI
};

class Derived1 : public Base
{
public:
    void show()
    {
        std::cout << "Derived1 class" << std::endl;
    }
};

class Derived2 : public Base
{
public:
    void show()
    {
        std::cout << "Derived2 class" << std::endl;
    }
};

int main()
{
    Base *basePtr = new Derived1(); // 实际类型是 Derived1

    // 尝试将 basePtr 转换为 Derived2* 类型
    Derived2 *derived2Ptr = dynamic_cast<Derived2 *>(basePtr);
    std::cout << "dynamic_cast: " << typeid(basePtr).name() << " to " << typeid(derived2Ptr).name() << std::endl;

    if (derived2Ptr)
    {
        derived2Ptr->show();
    }
    else
    {
        std::cout << "dynamic_cast failed: basePtr is not of type Derived2" << std::endl;
    }

    // 尝试将 basePtr 转换为 Derived2* 类型
    Derived2 *derived2Ptr2 = static_cast<Derived2 *>(basePtr);
    std::cout << "static_cast: " << typeid(basePtr).name() << " to " << typeid(derived2Ptr2).name() << std::endl;
    if (derived2Ptr2)
    {
        derived2Ptr2->show();
    }
    else
    {
        std::cout << "static_cast failed: basePtr is not of type Derived2" << std::endl;
    }

    Derived1 *derived1Ptr = new Derived1();
    // 尝试将 Derived1* 转换为 Derived2* 类型
    // Derived2 *derived2Ptr3 = static_cast<Derived2 *>(derived1Ptr); // 编译时报错
    Derived2 *derived2Ptr3 = dynamic_cast<Derived2 *>(derived1Ptr); // 编译时不报错，运行时derived2Ptr3为nullptr
    assert(derived2Ptr3 == nullptr);

    delete basePtr;
    return 0;
}