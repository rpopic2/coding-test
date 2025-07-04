#include <iostream>
#include <vector>

using matrix = std::vector<std::vector<int>>;

int dp_find(matrix &dp, int n, int m) {
    int &x = dp[n][m];
    if (x == 0) {
        x = dp_find(dp, n - 1, m - 1) + dp_find(dp, n, m - 1);
    }
    return x;
}

int main() {
    constexpr int DP_SIZE = 31;
    matrix dp(DP_SIZE, std::vector<int>(DP_SIZE));
    dp[1][1] = 1;
    for (int i = 1; i < DP_SIZE; ++i) {
        dp[i][i] = 1;
    }
    for (int i = 1; i < DP_SIZE; ++i) {
        dp[1][i] = i;
    }

    std::cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, m;
        std::cin >> n >> m;
        std::cout << dp_find(dp, n, m) << '\n';
    }
}

// 1 1 -> 1
//
// 1 2 -> 2
// 2 2 -> 1
//
// 1 3 -> 3
// 2 3 -> 2 + 1 = (1 2) + (2 2)
// 3 3 -> 1
//
// 1 4 -> 4
// 2 4 -> 6 = 3 + 2 + 1 = (1 3) + (2 3)
// 3 4 -> 4 = 2 + 1 + 1 = (2 3) + (3 3)
// 4 4 -> 1
//
// 1 5 -> 5
// 2 5 -> 4 + 3 + 2 + 1 = (1 4) + (2 4)
// 3 5 -> 3 + 2 + 1     = (2 4) + (3 4)
// 4 5 -> 2 + 1 + 1 + 1
// 5 5 -> 1
//
// 1 6 -> 6
// 2 6 -> 5 + 4 + 3 + 2 + 1 = (1 5) + (2 5)
// 3 6 -> 4 + 3 + 2 + 1 = (2 5) + (3 5)
// 3 6 -> (1 4) + (2 5)
// 4 6 -> 3 + 
//
// n m -> (n - 1 m - 1) + (n m - 1)
//
// cnt: 6
// | |
// | |
// | |
//   |
//   |
//   |


// 1. 숫자가 같으면 1
// 2. 1, n이면 n
