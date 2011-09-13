#include <iostream>

//Doesnt work yet in gcc
class Base
{
   public:
      Base(int n);
   private:
      int number_;
};

Base::Base(int n)
   :number_(n)
{
   std::cout << __PRETTY_FUNCTION__ << std::endl;
}

class Deriv : public Base
{
   public:
//      using Base::Base;
};

int main(int argc, char *argv[])
{
//   Deriv d(42);

   return 0;
}


