#include <iostream>

constexpr int getfive() { return 5; }

int array[getfive()*2];

int main()
{
   std::cout << sizeof(array) << std::endl;
   return 0;
}
