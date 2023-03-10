#include <iostream>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int restrict;
    std::cin >> restrict;

    int acc = 0;
    int car;
    for (int i = 0; i < 5; ++i) {
        std::cin >> car;
        if (restrict == car)
            acc += 1;
    }

    std::cout << acc << '\n';
}
