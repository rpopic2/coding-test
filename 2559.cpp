#include <iostream>
#include <numeric>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstdint>

using i64 = int64_t;

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> temp(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> temp[i];
    }

    i64 sum = std::accumulate(temp.begin(), std::next(temp.begin(), k), 0);
    // printf("init: %d\n", sum);
    i64 max_sum = sum;
    for (int i = 1; i + k <= n; ++i) {
        sum -= temp[i - 1];
        sum += temp[i + k - 1];
        // printf("a %d, b %d\n", temp[i - 1], temp[i + k - 1]);
        //
        // printf("sum %d: %lld\n", i, sum);
        max_sum = std::max(max_sum, sum);
    }
    std::cout << max_sum;
}

