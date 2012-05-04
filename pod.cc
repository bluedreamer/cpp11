#include <iostream>
#include <type_traits>

template<class T>
void foo(T t)
{
   if(std::is_reference<T>())
   {
      std::cout << "Its a reference\n";
   }

   if(std::is_pod<T>())
   {
      std::cout << "Its a pointer\n";
   }

   if(std::is_signed<T>())
   {
      std::cout << "Its signed\n";
   }

   if(std::is_object<T>())
   {
      std::cout << "Its an object\n";
   }

   if(std::is_integral<T>())
   {
      std::cout << "Its integral\n";
   }

   if(std::is_union<T>())
   {
      std::cout << "Its a union\n";
   }

   if(std::is_polymorphic<T>())
   {
      std::cout << "Its polymorphic\n";
   }
   std::cout << "-----\n";
}

int main(int argc, char *argv[])
{
   int a;
   class B
   {
      public:
         B() {}
   } b;
   class C
   {
   } c;

   class D : public B
   {
   } d;

   std::cout << std::is_pod<int>() << std::endl;
   std::cout << std::is_pod<B>() << std::endl;
   std::cout << std::is_pod<C>() << std::endl;

   int &e=a;

   size_t f;

   foo(a);
   foo(b);
   foo(c);
   foo(d);
   foo(e);
   foo(f);

   return 0;
}


