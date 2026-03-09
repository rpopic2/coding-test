#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;
    s.reserve(600'001);

    int m;
    std::cin >> m;

    auto cursor = s.end();
    for (int i = 0; i < m; ++i) {
        char cmd;
        std::cin >> cmd;

        if (cmd == 'L') {
            if (cursor == s.begin())
                continue;
            --cursor;
        } else if (cmd == 'D') {
            if (cursor == s.end())
                continue;
            ++cursor;
        } else if (cmd == 'B') {
            if (cursor == s.begin())
                continue;
            cursor = s.erase(cursor - 1);
        } else if (cmd == 'P') {
            char c;
            std::cin >> c;
            cursor = s.insert(cursor, c) + 1;
        }
        // printf("%d: %s\n", i, s.c_str());
    }

    std::cout << s << '\n';
}

