// #include <iostream>
// #include <vector>
#include <algorithm>
#include <cstdint>

using u64 = uint64_t;
using i64 = int64_t;

#include <stdint.h>
#include <stdio.h>

using u32 = uint32_t;
constexpr int BUF_SIZE = 1 << 16;
char buf[BUF_SIZE];
u32 cur, end;

char getc() {
    if (cur == end) {
        cur = 0;
        end = fread(buf, sizeof (char), BUF_SIZE, stdin);
        if (!end)
            return 0;
    }
    return buf[cur++];
}

i64 get_int() {
    i64 ret = 0;

    char current = getc();

    while (current <= ' ') {
        getc();
    }
    while (current >= '0') {
        ret = ret * 10 + current - '0';
        current = getc();
    }

    return ret;
}

int trees[1'000'000];
int main() {
    // std::cin.tie(nullptr)->sync_with_stdio(false);

    i64 n = get_int(), m = get_int(); // maybe u64
    // std::cin >> n >> m;

    // std::vector<int> trees(n);
    int tallest = 0;
    for (int i = 0; i < n; ++i) {
        int t = get_int();
        // std::cin >> t;
        trees[i] = t;
        tallest = std::max(tallest, t);
    }

    i64 upper = tallest;
    i64 lower = 0;
    i64 last_search = -1;
loop:
    // for (int i = 0; i < 3; ++i)
    {
    i64 search = ((upper - lower) / 2) + lower;
    if (last_search == search) {
        printf("%ld\n", search);
        fflush(stdout);
        _Exit(0);
    } else {
        last_search = search;
    }
    // std::cout << "search " << search << std::endl;
    i64 acc = 0;
    for (auto t : trees) {
        i64 diff = t - search;
        // std::cout << diff << ' ';
        if (diff > 0) {
            acc += diff;
        }
    }
    // std::cout << "acc was " << acc << std::endl;
    if (acc == m) {
        printf("%ld\n", search);
        fflush(stdout);
        _Exit(0);
    }
    if (acc > m) {
        lower = search;
    } else {
        upper = search;
    }
    }
    goto loop;
}

