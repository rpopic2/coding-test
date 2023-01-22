#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> coins(N);
    for (int i = 0; i < N; ++i) {
        cin >> coins[i];
    }
    vector<int> dp(K + 1, 0);
    dp[0] = 1;
    for (const auto &coin : coins) {
        for (int i = coin; i <= K; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    cout << dp[K];
}
