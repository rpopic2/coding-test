#include <iostream>
#include <vector>

long find_dp(std::vector<long> &dp, long index) {
    if (index <= 0)
        return 0;

    long &a = dp[index];
    if (a != 0) {
        return a;
    }

    a = find_dp(dp, index - 1) + find_dp(dp, index - 5);
    return a;
}

int main() {
    std::vector<long> dp;
    dp.reserve(100);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
        std::cout << find_dp(dp, n) << '\n';
    }
}

// 1 -> 1
// 2 -> 1
// 3 -> 1
// 4 -> 2
// 5 -> 2
// 6 -> 3
// 7 -> 4
// 8 -> 5
// 9 -> 7
// 10 -> 9
// 11 -> 12
// 12 -> 16

