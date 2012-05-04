#include <iostream>

struct Base 
{
   virtual void some_func(float);
};
     
struct Derived : Base 
{
// not implemented yet
//   virtual void some_func(int) override; // ill-formed because it doesn't override a base class method
   virtual void some_func(int); 
};

int main(int argc, char *argv[])
{

   return 0;
}


