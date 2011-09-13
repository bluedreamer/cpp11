#include <iostream>

class Default
{
   public:
      Default() {}
      Default(const std::string &s) {}
      Default(int i) :number_(i) {}
   private:
// construct3.cc:13:19: sorry, unimplemented: non-static data member initializers
// construct3.cc:13:19: error: ISO C++ forbids in-class initialization of non-const static member 'number_'
// construct3.cc: In constructor 'Default::Default()':
//      int number_=23;
      int number_;
};

int main(int argc, char *argv[])
{
   Default d1, d2("this is a test"), d3(42);
   return 0;
}


