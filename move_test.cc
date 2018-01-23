#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

class Object {
public:
    Object() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Object(const Object&) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Object(Object&&) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~Object() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Object& operator=(const Object&) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Object& operator=(Object&&) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
private:
};

void by_const_ref(const Object &o) {
    Object local = o;
}

void by_move(Object o) {
    Object local = std::move(o);
}

int main(int , char *[])
{
    {
        std::cout << "=====================================================\n";
        Object o;
        by_const_ref(o);
        std::cout << "=====================================================\n";
    }

    {
        std::cout << "=====================================================\n";
        Object o;
        by_move(std::move(o));
        std::cout << "=====================================================\n";
    }
    return 0;
}


