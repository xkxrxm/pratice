#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    vector<int*> v;
    v.push_back(new int(10));
    auto v2 = v;
    cout << *v[0] << endl;
    cout << *v2[0] << endl;
    *v[0] = 20;
    cout << *v[0] << endl;
    cout << *v2[0] << endl;
    
    map<int,int*> m;
    m[1] = new int(10);
    auto m2 = m;
    cout << *m[1] << endl;
    cout << *m2[1] << endl;
    *m[1] = 20;
    cout << *m[1] << endl;
    cout << *m2[1] << endl;

    return 0;
    // 说明：map和vector的拷贝构造函数都是浅拷贝，所以导致指针指向同一块内存，所以修改其中一个，另一个也会被修改
}
