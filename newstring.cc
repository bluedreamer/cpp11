#include <string>
#include <iostream>

int main()
{
   std::string s;

   s=std::to_string(-3425);
   std::cout << s << std::endl;

   long double ld=3.1243254523463465L;
   s=std::to_string(ld);
   std::cout << s << std::endl;

   return 0;
}
