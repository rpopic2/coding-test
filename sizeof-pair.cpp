#include <iostream>

int main() {
    std::pair<int, int> p;
    auto &rp = p;
    std::cout << sizeof(p) << std::endl;
    std::cout << sizeof(rp) << std::endl;

    int i = 1;
    auto &ri = i;
    std::cout << sizeof(i) << std::endl;
    std::cout << sizeof(ri) << std::endl;
}
