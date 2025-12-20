#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int m;
    std::cin >> m;

    std::vector<bool> vec(21);

    for (int i = 0; i < m; ++i) {
        std::string op;
        int arg;
        std::cin >> op;
        if (op != "all" && op != "empty")
            std::cin >> arg;

        if (op[0] == 'a') {
            vec[arg] = true;
        } else if (op[0] == 'r') {
            vec[arg] = false;
        } else if (op[0] == 'c') {
            int out;
            if (!vec[arg])
                out = 0;
            else
                out = 1;
            std::cout << out << '\n';
        } else if (op[0] == 't') {
            vec[arg] = !vec[arg];
        } else if (op[0] == 'a') {
            for (int i = 0; i < vec.size(); ++i) {
                vec[i] = true;
            }
        } else if (op[0] == 'e') {
            for (int i = 0; i < vec.size(); ++i) {
                vec[i] = false;
            }
        }
    }
}

