#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int first_row = n / 2;
    int second_row = first_row;

    if (n % 2 == 1) {
        first_row += 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < first_row; ++j) {
            std::cout << "* ";
        }
        std::cout << '\n';
        for (int j = 0; j < second_row; ++j) {
            std::cout << " *";
        }
        std::cout << '\n';
    }
}
