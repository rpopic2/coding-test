#include <algorithm>
#include <limits>
#include <cstdint>
#include <iostream>
#include <vector>
    using u64 = std::uint64_t;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    // road lens
    std::vector<int> lengths(n);
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> lengths[i];
    }

    // oil prices
    auto cheapest = std::numeric_limits<int>::max();
    u64 answer = 0;
    for (int i = 0; i < n; ++i) {
        int price;
        std::cin >> price;

        cheapest = std::min(cheapest, price);
        answer += (u64)lengths[i] * (u64)cheapest;
    }



    std::cout << answer;
}

