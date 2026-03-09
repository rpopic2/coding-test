#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string s;
    std::getline(std::cin, s);

    std::size_t len = s.length();
    auto it = s.begin();
    while (it != s.end()) {
        char c = *it;

        if (c == '<') {
            do {
                std::cout << *it;
                ++it;
            }
            while (*it != '>');
            std::cout << *it;
            ++it;
            continue;
        }
        //
        auto begin = it;
        c = *++it;
        while (c != ' ' && c != '<' && it != s.end()) {
            // std::cout << c;
            // std::cout.flush();
            c = *++it;
        }
        auto end = it;
        for (auto end = it; end >= begin; --it) {
            std::cout << *end;
            std::cout.flush();
        }
        // std::reverse(begin, it);
        // std::cout << std::string_view{begin, it};
        if (c == ' ') {
            std::cout << ' ';
            ++it;
        }
    }
    std::cout << '\n';
    // std::reverse(
}

