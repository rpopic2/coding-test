#include <iostream>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    constexpr int num_routines = 4;

    int acc = 0;
    int tmp;
    for (int i = 0; i < num_routines; ++i) {
        std::cin >> tmp;
        acc += tmp;
    }

    int hours = acc / 60;
    int minutes = acc % 60;
    std::cout << hours << '\n' << minutes;
}
