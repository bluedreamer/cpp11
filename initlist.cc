#include <iostream>
#include <string>
#include <vector>

class C
{
   public:
      C(std::initializer_list<int> l);
      void show() const;
   private:
      std::vector<int> data_;
};

C::C(std::initializer_list<int> l)
   :data_(l)
{
}

void C::show() const
{
   for(auto i=data_.begin(),end=data_.end(); i!=end; ++i)
   {
      std::cout << *i << ' ';
   }
   std::cout << std::endl;
}

void function(std::initializer_list<std::string> l);

int main(int argc, char *argv[])
{
   C c={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

   c.show();

   function({"this", "is", "a", "test"});

   std::initializer_list<int> a={3,2,1};
   C d(a), e(a);

   d.show();
   e.show();

   return 0;
}

void function(std::initializer_list<std::string> l)
{
   for(auto i=l.begin(),end=l.end(); i!=end; ++i)
   {
      std::cout << '\'' << *i << "' ";
   }
   std::cout << std::endl;
}
