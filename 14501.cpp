#include <iostream>
#include <vector>

int main() {
    size_t n;
    std::cin >> n;

    std::vector<int> dp(n+1);

    for (int cur_day = 0; cur_day <= n; ++cur_day) {
        int t, p;
        std::cin >> t >> p;
        if (cur_day + t <= n) {
            int &next = dp[cur_day + t];
            next = std::max(next,
                 dp[cur_day] + p);
        }

        if (cur_day + 1 <= n) {
            int &next = dp[cur_day + 1];
            next = std::max(next, dp[cur_day]);
        }
    }

    std::cout << dp[n];
}

