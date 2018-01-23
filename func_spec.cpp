#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

class Base
{
public:
    virtual std::string get() & {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return m_string;
    }
    virtual std::string get() && {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return m_string;
    }
private:
    std::string m_string;
};

class Derived : public Base
{
public:
    virtual std::string get() & override {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return Base::get();
    }
    virtual std::string get() && override {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return Base::get();
    }

private:
};

int main(int, char *[])
{
    Base b;
    b.get();
    std::cout << "-----\n";
    Derived d;
    d.get();
    std::cout << "-----\n";

    Derived().get();
    std::cout << "-----\n";
    Base().get();
    std::cout << "-----\n";

    return 0;
}


