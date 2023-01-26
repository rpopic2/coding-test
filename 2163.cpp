#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr auto endl = '\n';

vector<vector<int>> dp;

int divide(int n, int m) {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (n == 1 && m == 1) return 0;
    else if (m == 1)
    {
        auto &memo = dp[n][1];
        if (memo != 0) return memo;
        memo = divide(n - 1, 1) + 1;
        return dp[n - 1][1] + 1;
    }
    auto &memo = dp[n][m];
    if (memo != 0) return memo;
    memo = divide(n, m - 1) + divide(n, 1) + 1;
    return memo;
}
int main() {
    int n, m;
    cin >> n >> m;
    dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
    cout << divide(n, m) << ::endl;
}
// 1x1은 0
//
// 
// dp[2][2] = dp[2][1] + dp[2][1] + 1;
// dp[2][1] = dp[1][1] + dp[1][1] + 1;
//
// dp[3][3] = dp[3][2] + dp[3][1] + 1;
//
// dp[n][m] = dp[n][m - 1] + dp[n][1] + 1;
// if (m == 1) dp[n][1] = dp[n - 1][1] + dp[1][1] + 1;
// else if (m == 1 && m == 1) dp[1][1] = 0
// 
//
// 3x3은 2x3 + 1x3 +1 = 5 + 2 + 1 = 8
// 2x3은 1x3 + 1x3 +1 = 2 + 2 + 1 = 5
// 1x3은 1x2 + 1x1 +1 = 1 + 0 + 1 = 2
// 1x2는 1x1에 +1 = 0 + 1 = 1
// 결론적으로 3x3은 1x1에 +4 = 4
// 
// 2x2를 쪼개면 1x2, 1x2 두개 + 1
// 1x2는 1x1에 +1 = 1
// 결론적으로 2x2는 1 + 1 + 1 = 3
//
