#include <iostream>
#include <map>

int main(int argc, char *argv[])
{
   typedef std::map<int, std::string> Map;
   Map arr={{9, "nine"}, {8,"eight"}, {7,"seven"}, {6, "six"}, {5, "five"}};

   // Test1
   for(std::pair<int, std::string> i : arr)
   {
      std::cout << i.first << ' ' << i.second << ',';
   }
   std::cout << std::endl;

   // same as Test1 I believe
   // Test2
   for(Map::value_type i : arr)
   {
      std::cout << i.first << ' ' << i.second << ',';
   }
   std::cout << std::endl;

   // Test3
//error: invalid initialization of reference of type 
// 'std::pair<int, std::basic_string<char> >&' from expression of type 
// 'std::pair<const int, std::basic_string<char> >'
//
//   for(std::pair<int, std::string> &i : arr)
//   {
//      std::cout << i.first << ' ' << i.second << ',';
//   }
//   std::cout << std::endl;

   // Test4
   // Maybe this is not the same as Test3 - since the above will not compile
   for(Map::value_type &i : arr)
   {
      std::cout << i.first << ' ' << i.second << ',';
   }
   std::cout << std::endl;

   // Test5
   for(const Map::value_type &i : arr)
   {
      std::cout << i.first << ' ' << i.second << ',';
   }
   std::cout << std::endl;

   // And this works but the not const reference of std::pair does not
   // Test6
   for(const std::pair<int, std::string> i : arr)
   {
      std::cout << i.first << ' ' << i.second << ',';
   }
   std::cout << std::endl;

   // Test7
   // I really dont get why an iterator does not work? And what does it mean by 
   // non-scalar type
// error: conversion from 'std::pair<const int, std::basic_string<char> >' 
// to non-scalar type 'std::map<int, std::basic_string<char> >::const_iterator 
// {aka std::_Rb_tree_const_iterator<std::pair<const int, 
// std::basic_string<char> > >}' requested
//   for(Map::const_iterator i : arr)
//   {
//      std::cout << i->first << ' ' << i->second << ',';
//   }
//   std::cout << std::endl;

   // Test8
   for(auto i : arr)
   {
      // What is i here
      std::cout << i.first << ' ' << i.second << ',';
   }
   std::cout << std::endl;

   return 0;
}
