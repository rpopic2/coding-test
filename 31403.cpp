#include <iostream>

int main() {
    std::string a, b, c;
    std::cin >> a >> b >> c;

    std::cout << (std::stoi(a) + std::stoi(b) - std::stoi(c)) << '\n';
    std::cout << (std::stoi(a + b) - std::stoi(c)) << '\n';
}

