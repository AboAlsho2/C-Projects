#include <iostream>
#include <thread>
#include <type_traits>

void increment(int& n) {
    ++n;
}

int main() {
    int num = 5;
    std::thread t(increment, std::ref(num) ); // Pass by reference using std::ref
    t.join();
    std::cout << "Incremented value: " << num << std::endl;
    return 0;
}
