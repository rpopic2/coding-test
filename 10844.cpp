#include <iostream>
#include <vector>
#include <climits>

using u64 = unsigned long long;
using u32 = std::uint32_t;

constexpr u64 MOD = 1'000'000'000;

u64 n;
u64 answer = 0;

void recurse(int depth, char back) {
    if (depth == n) {
        answer += 1;
        if (answer == MOD) {
            answer = 0;
        }
        return;
    }

    if (back + 1 <= '9') {
        recurse(depth + 1, back + 1);
    }
    if (back - 1 >= '0') {
        recurse(depth + 1, back - 1);
    }
}

int main() {
    std::cin >> n;


    for (int i = 1; i <= 9; ++i) {
        recurse(1, i + '0');
    }

    std::cout << answer << '\n';
}

// n == 2; (12 23 34 45 56) (67 78 89 98 87) (76 65 54 43 32) 21 10
// n == 3; 121 123 101

