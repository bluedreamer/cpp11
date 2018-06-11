#pragma once

#include <iostream>

class TLocal {
public:
    TLocal() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};
