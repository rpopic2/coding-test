#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;
        std::cout << *s.begin() << *(s.end() - 1) << '\n';
    }
}

