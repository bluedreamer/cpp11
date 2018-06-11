#include <vector>
#include <thread>
#include <unistd.h>

bool running = false;

void boring_thread() {
    while(running) {
        sleep(1);
    }
}

void init() {
    running = true;
    std::vector<std::thread> threads;

    for(size_t i = 0; i < 10; ++i) {
        threads.push_back(std::thread(boring_thread));
    }
    while(running) {
        sleep(1);
    }
    for(auto& t : threads) {
        t.join();
    }
}

void stop() {
    running = false;
}
