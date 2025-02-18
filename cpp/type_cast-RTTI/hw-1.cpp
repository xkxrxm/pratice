#include <iostream>
#include <typeinfo>
using namespace std;

class Grand
{
private:
    int hold;

public:
    Grand(int h = 0) : hold(h) {}

    virtual void Speak() const
    {
        cout << "I am a grand class!\n";
    }

    virtual int Value() const
    {
        return hold;
    }
};

class Superb : public Grand
{
public:
    Superb(int h = 0) : Grand(h) {}

    void Speak() const override
    {
        cout << "I am a superb class!!\n";
    }

    virtual void Say() const
    {
        cout << "I hold the superb value of " << Value() << "!\n";
    }
};

class Magnificent : public Superb
{
private:
    char ch;

public:
    Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}

    void Speak() const override
    {
        cout << "I am a magnificent class!!!\n";
    }

    void Say() const override
    {
        cout << "I hold the character " << ch << " and the integer " << Value() << "!\n";
    }
};

int main()
{
    auto pg = new Grand(10);
    Superb *ps;

    if (ps = dynamic_cast<Superb *>(pg))
    {
        cout << "pg can be cast to Superb" << endl;
        ps->Say();
    }

    if (typeid(*pg) == typeid(Superb))
    {
        cout << "ps is a Superb" << endl;
        ((Superb *)pg)->Say();
    }
    return 0;
}