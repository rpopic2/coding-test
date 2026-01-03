#include <iostream>
#include <vector>
#include <limits>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> dp(1'000'002);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= n; ++i) {
        int case1 = std::numeric_limits<int>::max();
        int case2 = std::numeric_limits<int>::max();
        if (i % 3 == 0)
            case1 = dp[i / 3] + 1;
        if (i % 2 == 0)
            case2 = dp[i / 2] + 1;
        int case3 = dp[i - 1] + 1;
        dp[i] = std::min({case1, case2, case3});
    }

    std::cout << dp[n];
}

