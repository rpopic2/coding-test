#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int spaces_count = 0;
    while (n > 0) {
        std::cout << std::string(spaces_count++, ' ');
        std::cout << std::string(n * 2 - 1, '*') << '\n';
        --n;
    }
}
