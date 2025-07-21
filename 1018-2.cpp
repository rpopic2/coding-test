#include <iostream>
#include <vector>
#include <limits>

using matrix = std::vector<std::vector<char>>;

int check_board(const matrix &board, int start_x, int start_y, char expected) {
    int bad = 0;

    // printf("peek was %c(%d)\n", expected, expected);

    for (int i = start_x; i < start_x + 8; ++i) {
        for (int j = start_y; j < start_y + 8; ++j) {
            char c = board[i][j];
            if (c != expected) {
                ++bad;
                // printf("expected %c but got %c(%d, %d)\n", expected, c, i, j);
            }
            expected = expected == 'B' ? 'W' : 'B';
        }
        expected = expected == 'B' ? 'W' : 'B';
    }
    // printf("at (%d, %d): %d\n", start_x, start_y, bad);
    return bad;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    matrix checker_board(n, std::vector<char>(m));

    int min_recolor = std::numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> checker_board[i][j];
        }
    }

    for (int i = 0; i <= n - 8; ++i) {
        for (int j = 0; j <= m - 8; ++j) {
            int recolor = check_board(checker_board, i, j, 'B');
            if (recolor < min_recolor) {
                min_recolor = recolor;
            }
            recolor = check_board(checker_board, i, j, 'W');
            if (recolor < min_recolor) {
                min_recolor = recolor;
            }
        }
    }
    std::cout << min_recolor << '\n';
}

