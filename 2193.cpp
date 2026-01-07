#include <iostream>
#include <vector>

struct pair {
    size_t zeroes;
    size_t ones;
};

int main() {
    size_t n;
    std::cin >> n;

    std::vector<pair> memo(n + 1);
    memo[1] = {0, 1};
    for (size_t i = 2; i <= n; ++i) {
        const auto &prev = memo[i - 1];
        memo[i] = {.zeroes = prev.ones + prev.zeroes, .ones = prev.zeroes};
    }
    const auto &nth = memo[n];
    std::cout << nth.ones + nth.zeroes;
}

// 1
// 0b1

// 2
// 0b10

// 3
// 0b101
// 0b100

// 4
// 0b1010
// 0b1001
// 0b1000

// 5
// 0b10101
// 0b10100
// 0b10010
// 0b10000
// 0b10001
