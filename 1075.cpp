#include <iostream>
#include <string>

int main() {
    std::string raw_n;
    int f;

    std::cin >> raw_n >> f;

    // replace last two digits to zero
    int end = raw_n.size() - 1;
    raw_n[end] = '0';
    raw_n[end - 1] = '0';

    int n = std::stoi(raw_n);

    int ans = 0;
    while (n % f != 0) {
        ++ans;
        ++n;
    }
    if (ans < 10) {
        std::cout << '0';
    }
    std::cout << ans << '\n';
}
