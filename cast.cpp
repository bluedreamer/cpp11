#include <iostream>

struct Fahrenheit;
struct Celsius 
{
    explicit Celsius(double v) : m_value(v) {}
    operator Fahrenheit();
    double m_value;
};

struct Fahrenheit
{
    explicit Fahrenheit(double v) : m_value(v) {}
    operator Celsius() { return Celsius((m_value - 32) * (5.0/9.0));; }
    double m_value;
};
inline Celsius::operator Fahrenheit() { return Fahrenheit((9.0/5.0 * m_value) + 32); }

int main(int, char *[])
{
    auto F_to_C = static_cast<Fahrenheit>(static_cast<Celsius>(100));

    std::cout << F_to_C.m_value << 'F' << std::endl;

    auto C_to_F = static_cast<Celsius>(F_to_C);
    std::cout << C_to_F.m_value << 'C' << std::endl;

    return 0;
}


