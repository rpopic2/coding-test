#include <iostream>

int main() {
    std::string s;
    std::cin >> s;

    auto len = s.length();

    auto p = &s[0];
    auto rp = &s[len - 1];

    for (; p < rp; ++p, --rp) {
        if (*p != *rp) {
            std::cout << "0\n";
            return 0;
        }
    }

    std::cout << "1\n";
}
