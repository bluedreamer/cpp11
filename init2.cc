#include <iostream>
#include <string>

struct IdString1 
{
   std::string name;
   int identifier;
};

struct IdString2
{
   std::string street;
   int housenumber;
};

IdString1 get_string()
{
   return {"C++", 2};
}

// init2.cc:22:18: error: 'get_string2' function uses 'auto' type specifier without late return type
// auto get_string2()
// {
//    return {"C++", 2};
// }

int main(int argc, char *argv[])
{
   IdString1 id=get_string();
   const IdString1 cid=get_string();

   return 0;
}


