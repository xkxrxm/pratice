#include <iostream>
class myclass
{
private:
    int *data;

public:
    myclass(int value)
    {
        data = new int(value);
    }
    ~myclass()
    {
        delete data;
    }
    myclass(const myclass &other)
    {
        data = new int;
        *data = *other.data;
    }
    myclass &operator=(const myclass &other)
    {
        if (this != &other)
        {
            delete data;
            data = new int;
            *data = *other.data;
        }
        return *this;
    }
};