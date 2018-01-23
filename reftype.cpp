#include <iostream>
#include <string>
#include <type_traits>

template<class T>
void f(T&&) {
    auto r1 = std::is_lvalue_reference<T&&>::value;
    auto r2 = std::is_rvalue_reference<T&&>::value;

    if(r1) {
        std::cout << "Is lvalue reference\n";
    } else {
        std::cout << "Is not lvalue reference\n";
    }

    if(r2) {
        std::cout << "Is rvalue reference\n";
    } else {
        std::cout << "Is not rvalue reference\n";
    }
    std::cout << "-----------\n";
}

void g(auto && foo) {
    auto r1 = std::is_lvalue_reference<decltype(foo)>::value;
    auto r2 = std::is_rvalue_reference<decltype(foo)>::value;

    if(r1) {
        std::cout << "Is lvalue reference\n";
    } else {
        std::cout << "Is not lvalue reference\n";
    }

    if(r2) {
        std::cout << "Is rvalue reference\n";
    } else {
        std::cout << "Is not rvalue reference\n";
    }
    std::cout << "-----------\n";
}

int main(int , char *[])
{
    double x = 10;
    std::string s("this is a test");
    f(10.0);
    f("not" + s);
    f(x);
    f(s);
    std::cout << "================================================================================ \n";
    g(10.0);
    g("not" + s);
    g(x);
    g(s);

    return 0;
}


