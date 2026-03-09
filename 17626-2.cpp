#include <iostream>
#include <vector>
#include <cstring>

using u16 = unsigned short;
using u32 = unsigned;

int main() {
    int n;
    std::cin >> n;

    // constexpr u16 MAX = 50001;
    u16 memo[n+1];
    memset(memo, 0xff, sizeof memo);

    for (u32 i = 1; i*i < n + 1; ++i) {
        u32 sq = i * i;
        memo[sq] = 1;
        for (int i = sq + 1; i < n + 1; ++i) {
            u16 val = memo[sq] + memo[i - sq];
            memo[i] = val < memo[i] ? val : memo[i];
        }
    }

    std::cout << memo[n] << '\n';
}

