#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

template<class T> struct A {
    explicit A(const T&, ...) noexcept; // #1
    A(T&&, ...);                        // #2
};
template<class T> A(const T&, const T&) -> A<T&>; // #3
template<class T> explicit A(T&&, T&&)  -> A<T>;  // #4

int main(int, char *[])
{
    int i;
    //A a1 = { i, i }; // error: cannot deduce from rvalue reference in #2,
                     // and #1 is explicit, and not considered in copy-initialization.
    A a2{i, i};      // OK, #1 deduces to A<int> and also initializes
/*
    A a3{0, i};      // OK, #2 deduces to A<int> and also initializes
    A a4 = {0, i};   // OK, #2 deduces to A<int> and also initializes

*/
/*
    A a5 = {0, 1};   // error: #3 deduces to A<int&>
                         // and #1 & #2 result in same parameter constructors.
    A a6{0,1};       // OK, #4 deduces to A<int> and #2 initializes
    A a7 = {0, i};   // error: #3 deduces to A<int&>
    A a8{0,i};       // error: #3 deduces to A<int&>

*/
    return 0;
}


