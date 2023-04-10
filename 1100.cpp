#include <iostream>

int main() {
    constexpr int BOARD_SIZE = 8;

    std::cin.tie(nullptr)->sync_with_stdio(false);

    int counter = 0;

    std::string cur_line;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        std::cin >> cur_line;

        bool is_even_row = i % 2;

        for (int j = 0; j < BOARD_SIZE; ++j) {
            bool is_even_col = j % 2;
            if (is_even_row && is_even_col && cur_line[j] == 'F') {
                ++counter;
            }
            else if (!is_even_row && !is_even_col && cur_line[j] == 'F') {
                ++counter;
            }
        }
    }
    
    std::cout << counter << '\n';
}
