#include <iostream>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::string s;
    while (std::getline(std::cin, s)) {
        std::cout << s << '\n';
    }
}
