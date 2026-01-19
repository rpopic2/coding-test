#include <iostream>
#include <vector>
#include <cstdint>

using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    u64 n, m;
    std::cin >> n >> m;

    u64 count = 0;

    std::vector<u64> sums(n + 1);
    for (int i = 0; i < n; ++i) {
        u64 x;
        std::cin >> x;
        for (int j = 0; j <= i; ++j) {
            sums[j] += x;
            if (sums[j] == m) {
                count += 1;
            }
        }
    }
    std::cout << count << '\n';
}

