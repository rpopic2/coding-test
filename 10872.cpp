#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int acc = 1;
    for (int i = 1; i < n + 1; ++i) {
        acc *= i;
    }
    std::cout << acc << '\n';
}
