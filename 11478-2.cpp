#include <iostream>
#include <vector>
#include <cstdio>
#include <string_view>
#include <cstring>

int common(std::string_view sv, std::string_view sv2) {
    int result = 0;
    for (int i = 0; i < sv.size(); ++i) {
        if (sv[i] == sv2[i])
            ++result;
        else return result;
    }
    return result;
}

int main() {
    char s[1001] = {0};
    std::fread(s, sizeof (char), 1001, stdin);
    // std::cin >> s;
    auto s_size = std::strlen(s);

    std::vector<std::string_view> suffix;
    for (size_t i = 0; i < s_size; ++i) {
        suffix.emplace_back(&s[i], s_size - i);
    }
    std::sort(suffix.begin(), suffix.end());

    auto unique = (s_size * (s_size + 1)) / 2;
    for (size_t i = 1; i < s_size; ++i) {
        unique -= common (suffix[i - 1], suffix[i]);

        std::printf("%zd\n", unique);
    }
    std::printf("%zd\n", unique);
    // std::cout << unique << '\n';

    // for (auto x : suffix) {
    //     std::cout << x << ", ";
    // }
    // std::cout << '\n';
}

