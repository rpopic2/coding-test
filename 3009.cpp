#include <iostream>
#include <array>

int main() {
    constexpr int X = 0;
    constexpr int Y = 1;
    constexpr int ROW = 3;
    constexpr int COL = 2;

    std::array<std::array<int, ROW>, COL> matrix;

    for (int i = 0; i < ROW; ++i) {
        std::cin >> matrix[X][i] >> matrix[Y][i];
    }

    for (int i = 0; i < COL; ++i) {
        auto &vector = matrix[i];
        if (vector[0] == vector[1]) {
            std::cout << vector[2];
        } else if (vector[1] == vector[2]) {
            std::cout << vector[0];
        } else {
            std::cout << vector[1];
        }
        std::cout << ' ';
    }
    std::cout << '\n';
}

