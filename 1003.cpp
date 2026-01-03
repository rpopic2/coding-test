#include <iostream>
#include <vector>

using pair = std::pair<int, int>;

int main() {
    int t;
    std::cin >> t;

    std::vector<pair>dp(41);

    dp[0] = {1, 0};
    dp[1] = {0, 1};
    dp[2] = {1, 1};
    dp[3] = {1, 2};
    for (int i = 2; i < 41; ++i) {
        auto minus2 = dp[i - 2];
        auto minus1 = dp[i - 1];
        dp[i] = {minus2.first + minus1.first, minus2.second + minus1.second};
    }

    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
        const auto &p = dp[n];
        std::cout << p.first << ' ' << p.second << '\n';
    }
}

