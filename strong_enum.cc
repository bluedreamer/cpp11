#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

enum class Colour {Red, Green, Blue, Orange, Purple};
enum class Dataline {Red,Green,Yellow,Blue};

int main(int argc, char *argv[])
{
   Colour a=Colour::Blue;
   Dataline dl=Dataline::Blue;

   // strong_enum.cc:22:10: error: no match for 'operator==' in 'a == dl'
   // strong_enum.cc:22:10: note: candidates are:
   // strong_enum.cc:22:10: note: operator==(Dataline, Dataline) <built-in>
   // strong_enum.cc:22:10: note:   no known conversion for argument 1 from 'Colour' to 'Dataline'
   // strong_enum.cc:22:10: note: operator==(Colour, Colour) <built-in>
   // strong_enum.cc:22:10: note:   no known conversion for argument 2 from 'Dataline' to 'Colour'
   // if(a==dl)
   {
      std::cout << "true\n";
   }

   // strong_enum.cc:28:6: error: cannot convert 'Dataline' to 'Colour' in assignment
   // a=dl;


   return 0;
}


