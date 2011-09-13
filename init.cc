#include <iostream>

struct BasicStruct 
{
   int x;
   double y;
};
         
struct AltStruct 
{
      AltStruct(int x, double y) : x_{x}, y_{y} {}
   private:
      int x_;
      double y_;
};
                       
int main(int argc, char *argv[])
{
   BasicStruct var1{5, 3.2};
   AltStruct var2{2, 4.3};

   return 0;
}


