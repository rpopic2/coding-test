#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

int main() {
    constexpr int SIZE = 9;

    std::vector<int> leprechans(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        std::cin >> leprechans[i];
    }
    std::sort(leprechans.begin(), leprechans.end());

    const int sum = std::accumulate(leprechans.begin(), leprechans.end(), 0);
    // std::printf("sum: %d\n", sum);
    const int diff = sum - 100;

    std::vector<int> excludes;

    for (int i = 0; i < SIZE - 1; ++i) {
        for (int j = i + 1; j < SIZE; ++j) {
            if (leprechans[i] + leprechans[j] == diff) {
                excludes.push_back(leprechans[i]);
                excludes.push_back(leprechans[j]);
                goto brk;
            }
        }
    }
brk:

    for (int x : leprechans) {
        if (x != excludes[0] && x != excludes[1])
            std::cout << x << '\n';
    }
}

