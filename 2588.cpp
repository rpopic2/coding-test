#include <iostream>
#include <cmath>
constexpr int DIGITS = 3;
int main () {
    int lhs;
    std::string rhs;
    std::cin >> lhs;
    std::cin >> rhs;
    auto acc = 0;
    for (int i = DIGITS - 1, j = 0; i >= 0; --i, ++j) {
        auto product = lhs * (rhs[i] - '0');
        std::cout << product << '\n';
        acc += product * pow(10, j);
    }
    std::cout << acc;
}
