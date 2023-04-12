#include <iostream>
#include <bitset>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::bitset<10'000> bs;

    int min = -1;
    int sum = 0;

    for (int i = n; i <= m; i += 2) {
        if (bs[i])
            continue;
        for (int j = 2; i * j <= m; ++j) {
            if (min == -1)
            bs[i * j] = true;
        }
    }
}
