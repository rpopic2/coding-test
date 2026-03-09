#include <iostream>
#include <vector>

using u16 = unsigned short;
using u32 = unsigned;

int main() {
    int n;
    std::cin >> n;

    //222
#define MAX 224
    u16 dp[MAX];
    for (u32 i = 0; i < MAX; ++i) {
        dp[i] = i * i;
    }

    u16 i = MAX - 1;
    int count = 0;
    while (n) {
        if (i == 0) {
            break;
        }
        if (dp[i] <= n) {
            n -= dp[i];
            count += 1;
            printf("%d\n", i);
        } else {
            --i;
        }
    }
    std::cout << count << '\n';
}

