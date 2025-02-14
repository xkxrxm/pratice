#include <iostream>
class ShallowCopy {    
    public:
        int *ptr;
        ShallowCopy(){
            ptr = nullptr;
        }
        ~ShallowCopy(){
            delete ptr;
        }
        ShallowCopy(ShallowCopy &other){
            ptr = other.ptr;
        }
};
int main() {
    ShallowCopy obj1;
    obj1.ptr = new int(10);
    ShallowCopy obj2 = obj1;
    std::cout << *obj1.ptr << std::endl;
    std::cout << *obj2.ptr << std::endl;
    *obj1.ptr = 20;
    std::cout << *obj1.ptr << std::endl;
    std::cout << *obj2.ptr << std::endl;
    // 浅拷贝会导致double free
}