#include <iostream>
#include <unordered_set>
#include <string_view>
#include <cstdint>

using isize = std::ptrdiff_t;
using usize = std::size_t;
int main() {
    std::string s;
    std::cin >> s;

    std::unordered_set<std::string_view> set;

    // std::string_view sv(s);

    for (usize i = 1; i <= s.size(); ++i) {
        for (auto it = s.begin();
                std::next(it, i - 1) != s.end();
                ++it) {
            auto a = it.base();
            set.emplace(a, i);
        }
    }

    std::cout << set.size() << '\n';
}

