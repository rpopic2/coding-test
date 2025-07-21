#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    using matrix = std::vector<std::vector<char>>;
    matrix checker_board(n, std::vector<char>(m));

    char last = '\0';
    int bad = 0;

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            last = checker_board[i - 1][0];
        }
        for (int j = 0; j < m; ++j) {
            char c;
            std::cin >> c;
            checker_board[i][j] = c;
            if (last == c) {
                ++bad;
                // printf("%c %c\n", last, c);
            }
            last = c;
        }
    }
    std::cout << bad << '\n';
}

