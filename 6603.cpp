#include <iostream>
#include <vector>

std::uint16_t s[13];
std::vector<std::uint16_t> buf(6);
std::size_t k;

void recurse2(int start) {
    if (buf.size() == 6) {
        for (auto x : buf) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
        return;
    }
    for (int i = start; i < k; ++i) {
        buf.push_back(s[i]);
        recurse2(i + 1);
        buf.pop_back();
    }
}

void recurse(int n) {
    buf.clear();
    for (int i = 0; i < n; ++i) {
        buf.push_back(s[i]);
    }
    recurse2(n + 1);
}

int main() {
    while (true) {
        std::cin >> k;
        if (k == 0) {
            return 0;
        }

        for (size_t i = 0; i < k; ++i) {
            std::cin >> s[i];
        }
        for (int i = 6; i >= 0; --i) {
            recurse(i);
        }
        std::cout << '\n';
    }
}

