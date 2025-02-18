#include <iostream>

int main() {
    int num = 65;
    int a = 10;
    char* charPtr = reinterpret_cast<char*>(&num);
    double* doublePtr = reinterpret_cast<double*>(&a);

    std::cout << "Interpreted value: " << *charPtr << std::endl; // 输出 'A'，因为 65 的 ASCII 码是 'A'
    std::cout << "Interpreted value: " << *doublePtr << std::endl; // 并不会输出 10.0，而是用double解释了 a 的值 1.3793e-312

    uintptr_t intPtr = reinterpret_cast<uintptr_t>(charPtr);
    std::cout << "Pointer as integer: " << intPtr << std::endl;

    return 0;
}