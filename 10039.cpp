#include <algorithm>
#include <iostream>
#include <ostream>

int main() {
    int acc = 0;
    for (int c, i = 0; i < 5; ++i) {
        std::cin >> c;
        acc += std::max(c, 40);
    }
    acc /= 5;
    std::cout << acc << std::endl;
}
