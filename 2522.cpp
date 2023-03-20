#include <iostream>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    std::cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < N - i; ++j) {
            std::cout << ' ';
        }
        for (int j = 0; j < i; ++j) {
            std::cout << '*';
        }
        std::cout << '\n';
    }

    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j < N - i; ++j) {
            std::cout << ' ';
        }
        for (int j = 0; j < i; ++j) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}
