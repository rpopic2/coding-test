#include <iostream>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int acc = 0;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int buf;
        std::cin >> buf;
        acc += buf;
    }

    acc -= n - 1;
    std::cout << acc << '\n';
}
