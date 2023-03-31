#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 1)
            std::cout << ' ';

        for (int j = 0; j < n; ++j) {
            std::cout << '*' << ' ';
        }
        std::cout << '\n';
    }
}
