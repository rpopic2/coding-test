#include <iostream>
using namespace std;
constexpr int MAX_SIZE = 14;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int dp[MAX_SIZE + 1][MAX_SIZE];
    for (int j = 0; j < MAX_SIZE; ++j)
    {
        dp[0][j] = j + 1;
    }
    for (int i = 1; i < MAX_SIZE + 1; ++i)
    {
        dp[i][0] = 1;
        for (int j = 1; j < MAX_SIZE; ++j)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    int T;
    cin >> T;
    while (T--)
    {
        int J, K; // >> K starts from 1!! <<
        cin >> J >> K;
        cout << dp[J][--K] << '\n';
    }
}

// given k, n,
// dp[0][0] = 1;
// dp[0][1] = 2;
// dp[0][2] = 3;
// 
// dp[1][0] = dp[0][0]; = 1
// dp[1][1] = (dp[0][0..1]).sum = 3
// dp[1][2] = (dp[0][0..2]).sum = 6
//
// dp[2][0] = dp[1][0]; = 1
// dp[2][1] = (dp[1][0..1]).sum = 4
// dp[2][2] = (dp[1][0..2]).sum = 10
//
// dp[k][n] = (dp[k - 1][0..n]).sum
//
// dp[k][n] = dp[k - 1][n] + dp[k][n - 1]
