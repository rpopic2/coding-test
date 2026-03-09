#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string front;
    std::cin >> front;
    front.reserve(600'001);

    std::string back;
    back.reserve(600'001);

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        char cmd;
        std::cin >> cmd;

        if (cmd == 'L') {
            if (front.empty())
                continue;
            back.push_back(front.back());
            front.pop_back();
        } else if (cmd == 'D') {
            if (back.empty())
                continue;
            front.push_back(back.back());
            back.pop_back();
        } else if (cmd == 'B') {
            if (front.empty())
                continue;
            front.pop_back();
        } else if (cmd == 'P') {
            char c;
            std::cin >> c;
            front.push_back(c);
        }
        // printf("%d: %s %s\n", i, front.c_str(), back.c_str());
    }

    std::reverse(back.begin(), back.end());
    std::cout << front << back << '\n';
}

