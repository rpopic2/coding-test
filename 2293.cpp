//보는 사람을 배려하는 코드를 짜자
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class sorter {
public:
    bool operator()(const int &lhs, const int &rhs) const {
        return lhs > rhs;
    }
};

int main() {
    int N, K;
    cin >> N >> K;
    set<int, sorter> coins;
    int value;
    for (int i = 0; i < N; ++i) {
        cin >> value;
        if (value > K) continue;
        coins.insert(value);
    }
    const int coin_max = *coins.cbegin();

    vector<vector<int>> dp(coin_max + 1);
    dp[1].resize(2);
    dp[1][1] = 1;
    for (int i = 2; i <= K; ++i) {
        dp[i] = vector<int>(i, 0);
        for (const auto &coin : coins) {
            if (coin > i) break;
            else if (coin == i )
            {
                dp[i][coin] = 1;
                continue;
            }
            auto diff = i - coin;
            dp[i][coin] = dp[diff][std::min(diff, coin)];
        }
    }
    int acc = 0;
    //for (int i = 0; i <= coin_max; ++i) {
        //acc += dp[K][i];
    //}
    for (const auto &i : dp) {
        for (const auto &j : dp) {
            for (const auto &k : j) {
                cout << k;
            }
        }
    }
    //cout << acc;
}
