#include <cmath>
#include <iostream>

int ctob(const char c) {
    auto diff = c - 'A';
    if (diff >= 0) {
        return 10 + diff;
    } else {
        return c - '0';
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::string n;
    int b;
    std::cin >> n >> b;

    int acc = 0;
    int digit_counter = 0;
    for (auto c = n.rbegin(); c != n.rend(); ++c) {
        auto cur_digit = ctob(*c);
        acc += cur_digit * (std::pow(b, digit_counter));
        ++digit_counter;
    }
    std::cout << acc << '\n';
}
// F4 -> 4 + F * 16 = 
// FF4 -> 4 + F * 16 + F * 16 * 16
// -> 4 + 240 + 3840
// cur_digit * (b ^ digit_pos)
