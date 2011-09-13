#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>

int main(int argc, char *argv[])
{
   int arr1[]={9,8,7,6,5,4,3,2,1,0};

   std::cout << "arr1: ";
   for(int &i : arr1)
   {
      std::cout << i << ' ';
   }
   std::cout << std::endl;

   std::cout << "arr1: ";
   for(int &i : arr1)
   {
      i*=12;
      std::cout << i << ' ';
   }
   std::cout << std::endl;

   std::cout << "arr1: ";
   for(int &i : arr1)
   {
      std::cout << i << ' ';
   }
   std::cout << std::endl;

   std::vector<int> arr2={9,8,7,6,5,4,3,2,1,0};
   std::cout << "arr2: ";
   for(int &i : arr2)
   {
      std::cout << i << ' ';
   }
   std::cout << std::endl;

   std::list<int> arr3={9,8,7,6,5,4,3,2,1,0};
   std::cout << "arr3: ";
   for(int &i : arr3)
   {
      std::cout << i << ' ';
   }
   std::cout << std::endl;

   std::map<int, std::string> arr4={{9, "nine"}, {8,"eight"}, {7,"seven"}, {6, "six"}, {5, "five"}};
   std::cout << "arr4: ";
   for(std::pair<int, std::string> i : arr4)
   {
      std::cout << i.first << ' ' << i.second << ',';
   }
   std::cout << std::endl;


   return 0;
}


