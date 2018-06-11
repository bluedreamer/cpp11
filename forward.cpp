#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

void func(int &, double&)
{
}

template<class T1, class T2>
void wrapper(T1& t1, T2& t2) {
    func(t1, t2);
}

int main(int argc, char *argv[])
{
    wrapper(1, 3.14);

    return 0;
}


