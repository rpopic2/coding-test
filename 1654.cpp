#include <iostream>
#include <vector>
#include <cstdint>

using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    u32 k, n;
    std::cin >> k >> n;

    u32 max = 0;
    std::vector<u32> lines(k);
    for (u32 i = 0; i < k; ++i) {
        u32 len;
        std::cin >> len;
        lines[i] = len;
        max = std::max(max, len);
    }

    u32 begin = 0, end = max;
    u32 candidate = 0;
    u32 last_cur = -1;
    while (true) {
        u32 cur = (end + begin) / 2;
        if (cur == begin)
            cur += 1;
        if (last_cur == cur)
            break;
        last_cur = cur;
        if (cur == candidate) {
            break;
        }
        u64 acc = 0;
        for (u32 l : lines) {
            acc += l / cur;
        }
        if (acc >= n) {
            if (cur > candidate) {
                candidate = cur;
            }
            begin = cur;
        } else {
            end = cur;
        }
    }
    std::cout << candidate;
}

