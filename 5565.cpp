#include <iostream>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int grand_total;
    std::cin >> grand_total;

    int buf;
    for (int i = 0; i < 9; ++i) {
        std::cin >> buf;
        grand_total -= buf;
    }

    std::cout << grand_total << '\n';
}
