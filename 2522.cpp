#include <iostream>

inline void print(char c, int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << c;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    std::cin >> N;

    for (int i = 1; i <= N; ++i) {
        print(' ', N - i);
        print('*', i);
        std::cout << '\n';
    }

    for (int i = N - 1; i >= 0; --i) {
        print(' ', N - i);
        print('*', i);
        std::cout << '\n';
    }
}
