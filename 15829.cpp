#include <iostream>
#include <cmath>
#include <cstdint>

using u64 = uint64_t;

constexpr u64 m = 1234567891ull;

int main() {
    u64 l;
    std::string s;
    std::cin >> l >> s;

    u64 acc = 0;
    u64 powt = 31;

    char c = s[0];
    acc += (c - 'a' + 1);

    for (u64 i = 1; i < l; ++i) {
        char c = s[i];
        acc += ((c - 'a' + 1) * powt);
        acc %= m;
        powt = (powt * 31) % m;
    }

    u64 hash = acc;
    std::cout << hash;
}

