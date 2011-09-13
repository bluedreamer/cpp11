#include <iostream>
// Not working in gcc4.6.0 yet

class Number
{
   public:
      Number();
      Number(int n);
      ~Number();
   private:
      int number_;
};

Number::Number()
//   :Number(54321)
{
   std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Number::Number(int n)
   :number_(n)
{
   std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Number::~Number()
{
   std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main(int argc, char *argv[])
{
   Number n;
   Number n2(23);

   return 0;
}


