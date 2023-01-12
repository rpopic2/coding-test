#include <iostream>
#include <string>
#include <bitset>
constexpr int MAX_SELF_NUM = 10'000;
int d(int n) {
    auto s = std::to_string(n);
    for (auto &c : s) {
        n += c - '0';
    }
    return n;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::bitset<MAX_SELF_NUM> non_selfnums;
    for (int i = 1; i < MAX_SELF_NUM; ++i) {
        if (non_selfnums[i]) continue;
        std::cout << i << '\n';
        for (int n = d(i); n < MAX_SELF_NUM; n = d(n)) {
            non_selfnums[n] = true;
        }
    }
}
