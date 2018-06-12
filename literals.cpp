#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

namespace literals::temperature
{
constexpr auto CelsiustoKelvin(long double v) -> long double { return v + 273.15; }
constexpr auto KelvintoCelsius(long double v) -> long double { return v - 273.15; }
constexpr auto CelsiustoFarenheit(long double v) -> long double { return (9.0/5.0 * v) + 32; }
constexpr auto FahrenheittoCelsius(long double v) -> long double { return (v - 32) * (5.0/9.0); }
constexpr auto KelvintoFahrenheit(long double v) -> long double { return (9.0/5.0) * (v - 273.15) + 32; }
constexpr auto FahrenheittoKelvin(long double v) -> long double { return (5.0/9.0) * (v - 32) + 273.15; }

class Kelvin;
class Fahrenheit;
class Celsius
{
public:
    constexpr explicit Celsius(long double v) : m_value(v) {}
    constexpr explicit Celsius(unsigned long long v) : m_value(v) {}
    Celsius(const Kelvin& v);
    Celsius(const Fahrenheit& v);

    constexpr auto operator-() const -> Celsius { return Celsius(-m_value); }
    constexpr auto operator+(const Celsius& v) const -> Celsius { return Celsius(m_value + v.m_value); }
    constexpr auto operator-(const Celsius& v) const -> Celsius { return Celsius(m_value - v.m_value); }

    auto value() const -> long double { return m_value; }
    friend auto operator<<(std::ostream& os, const Celsius& rhs) -> std::ostream& { os << rhs.m_value << 'C'; return os; }
private:
    long double m_value;
};

class Kelvin
{
public:
    constexpr explicit Kelvin(long double v) : m_value(v) {}
    constexpr explicit Kelvin(unsigned long long v) : m_value(v) {}
    Kelvin(const Celsius & v) : m_value(CelsiustoKelvin(v.value())) {}
    Kelvin(const Fahrenheit& v);

    constexpr auto operator-() const -> Kelvin { return Kelvin(-m_value); }
    constexpr auto operator+(const Kelvin& v) const -> Kelvin { return Kelvin(m_value + v.m_value); }
    constexpr auto operator-(const Kelvin& v) const -> Kelvin { return Kelvin(m_value - v.m_value); }

    auto value() const -> long double { return m_value; }

    friend auto operator<<(std::ostream& os, const Kelvin& rhs) -> std::ostream& { os << rhs.m_value << 'K'; return os; }
private:
    long double m_value;
};

class Fahrenheit
{
public:
    constexpr explicit Fahrenheit(long double v) : m_value(v) {}
    constexpr explicit Fahrenheit(unsigned long long v) : m_value(v) {}
    Fahrenheit(const Celsius & v) : m_value(CelsiustoFarenheit(v.value())) {}
    Fahrenheit(const Kelvin& v) : m_value(KelvintoFahrenheit(v.value())) {}

    constexpr auto operator-() const -> Fahrenheit { return Fahrenheit(-m_value); }
    constexpr auto operator+(const Fahrenheit& v) const -> Fahrenheit { return Fahrenheit(m_value + v.m_value); }
    constexpr auto operator-(const Fahrenheit& v) const -> Fahrenheit { return Fahrenheit(m_value - v.m_value); }

    auto value() const -> long double { return m_value; }

    friend auto operator<<(std::ostream& os, const Fahrenheit& rhs) -> std::ostream& { os << rhs.m_value << 'F'; return os; }
private:
    long double m_value;
};

inline Celsius::Celsius(const Kelvin& v) : m_value(KelvintoCelsius(v.value())) {}
inline Celsius::Celsius(const Fahrenheit& v) : m_value(FahrenheittoCelsius(v.value())) {}
inline Kelvin::Kelvin(const Fahrenheit& v) : m_value(FahrenheittoKelvin(v.value())) {}

inline auto operator "" _C(long double v) -> Celsius { return Celsius(v); }
inline auto operator "" _C(unsigned long long v) -> Celsius { return Celsius(v); }
inline auto operator "" _K(long double v) -> Kelvin { return Kelvin(v); }
inline auto operator "" _K(unsigned long long v) -> Kelvin { return Kelvin(v); }
inline auto operator "" _F(long double v) -> Fahrenheit { return Fahrenheit(v); }
inline auto operator "" _F(unsigned long long v) -> Fahrenheit { return Fahrenheit(v); }

} // end of namespace

int main(int , char *[])
{
    using namespace literals::temperature;
    auto a = 23_C;
    auto b = 87_F;
    auto c = 317_K;
    auto temp = a + b + c;
    std::cout << a << " + " << b << " + " << c << " = " << temp << " or " << Fahrenheit(temp) << " or " << Kelvin(temp) << std::endl;

    return 0;
}
