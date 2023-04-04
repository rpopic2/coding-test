#include <iostream>
#include <array>

int main() {
    constexpr int MAX_STUDENTS = 30;
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::array<bool, MAX_STUDENTS + 1> students{};

    int buf;
    for (int i = 0; i < MAX_STUDENTS - 2; ++i) {
        std::cin >> buf;
        students[buf] = true;
    }

    for (int i = 1; i < 31; ++i) {
        if (!students[i])
            std::cout << i << '\n';
    }
}
