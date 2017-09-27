#include <iostream>
#include <chrono>

int main(int, char *[])
{
    std::cout << "hrc is_steady = " << std::chrono::high_resolution_clock::is_steady << std::endl;
    std::chrono::high_resolution_clock::rep r;
    std::chrono::high_resolution_clock::period p;
    std::chrono::high_resolution_clock::duration d;
    std::chrono::high_resolution_clock::time_point t;

    std::cout << "hrc period = " << p.num << "/" << p.den << std::endl;

    for(size_t i = 0; i < 1; ++i) {
        // std::chrono::high_resolution_clock::time_point time_now = std::chrono::high_resolution_clock::now();
        auto time_now = std::chrono::high_resolution_clock::now();
        //std::chrono::high_resolution_clock::duration d = time_now.time_since_epoch();
        auto d = time_now.time_since_epoch();
        std::cout << d.count() << std::endl;

        d.zero();
    }

    return 0;
}


