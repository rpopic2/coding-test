using u64 = unsigned long long;
using u32 = std::uint32_t;

#include <iostream>
#include <vector>

constexpr u64 MOD = 1'000'000'000;

int main() {
    u64 n;
    std::cin >> n;

    std::vector<u64> dp(10);
    std::vector<u64> dp2(10);
    for (int i = 1; i <= 9; ++i) {
        dp[i] = 1;
    }
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i <= 9; ++i) {
            u64 tmp = 0;
            if (i - 1 >= 0) {
                tmp += dp[i - 1];
            }
            if (i + 1 <= 9) {
                tmp += dp[i + 1];
            }
            dp2[i] = tmp % MOD;
        }

        std::swap(dp, dp2);
    }

    u64 acc = 0;
    for (int i = 0; i <= 9; ++i) {
        acc += dp[i];
        acc %= MOD;
    }
    std::cout << acc << '\n';
}

// n == 1; 9; 1 ~ 9
// n == 2; 10 21 12 32 23 43 34 54 45 65 56 76 67 87 78 98 89
// n == 3; 210; 101, 121, 321; 212, 232, 432; 123, 323, 343, 543;
// n == 2; 17; (12 23 34 45 56) (67 78 89 98 87) (76 65 54 43 32) 21 10
// n == 3; 32; 121 123 101

