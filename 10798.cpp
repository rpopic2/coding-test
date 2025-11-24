#include <iostream>
#include <vector>

int main() {
    constexpr int LINES = 5;

    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::vector<std::string> lines(LINES);

    for (int i = 0; i < LINES; ++i) {
        std::cin >> lines[i];
        // longest = std::max(longest, lines[i].size());
    }

    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < LINES; ++j) {
            if (i >= lines[j].size())
                continue;
            std::cout << lines[j][i];
        }
    }
    std::cout << std::endl;
}

