#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

class Contrived
{
public:
    Contrived(const char *) { std::cout << __PRETTY_FUNCTION__  << std::endl; }
    Contrived() { std::cout << __PRETTY_FUNCTION__  << std::endl; }
    ~Contrived() { std::cout << __PRETTY_FUNCTION__  << std::endl; }
    Contrived(const Contrived&) { std::cout << __PRETTY_FUNCTION__  << std::endl; }
    Contrived(Contrived&&) { std::cout << __PRETTY_FUNCTION__  << std::endl; }
private:
};

Contrived foo()
{
    char data[10];

    return Contrived{data};
}

int main(int argc, char *argv[])
{
    auto f = foo();

    std::cout << "-\n";

    return 0;
}


