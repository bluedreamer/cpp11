#include <iostream>
#include <typeinfo>

template<class Lhs, class Rhs>
auto addit(const Lhs &lhs, const Rhs &rhs) -> decltype(lhs+rhs) 
{ 
   return lhs+rhs; 
}

int main(int argc, char *argv[])
{
   char c=23;
   char d=33;
   auto rc1=addit(c,d);
   std::cout << rc1 << ' ' << typeid(rc1).name() << std::endl;

   char e=245;
   char f=254;
   auto rc2=addit(e,f);
   std::cout << rc2 << ' ' << typeid(rc2).name() << std::endl;

   unsigned long ul=3214954L;
   double dd=3.142;
   auto rc3=addit(ul,dd);
   std::cout << rc3 << ' ' << typeid(rc3).name() << std::endl;

   return 0;
}


