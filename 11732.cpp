#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int m;
    std::cin >> m;

    std::vector<int> vec;

    for (int i = 0; i < m; ++i) {
        std::string op;
        int arg;
        std::cin >> op >> arg;

        if (op == "add") {
            auto it = std::find(vec.begin(), vec.end(), arg);
            if (it != vec.end())
                vec.push_back(arg);
        } else if (op == "remove") {
            std::erase(vec, arg);
        } else if (op == "check") {
            auto it = std::find(vec.begin(), vec.end(), arg);
            int out;
            if (it == vec.end())
                out = 0;
            else
                out = 1;
            std::cout << out << '\n';
        } else if (op == "toggle") {
            auto it = std::find(vec.begin(), vec.end(), arg);
            if (it == vec.end())
                vec.push_back(arg);
            else
                std::erase(vec, arg);
        } else if (op == "all") {
            vec.clear();
            vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        } else if (op == "empty") {
            vec.clear();
        }
    }
}

