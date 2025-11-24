#include <iostream>
#include <vector>

struct Point {
    int i, j;

    Point operator+(const Point &rhs) {
        return {i + rhs.i, j + rhs.j};
    }
};

enum Direction {
    LEFT, RIGHT, UP, DOWN
};
Direction direction_enums[] {
    LEFT, RIGHT, UP, DOWN,
};

Point directions[] {
    {0, -1}, {0, 1}, {-1, 0}, {1, 0},
};

class Board : public std::vector<std::vector<int>> {
public:
    using matrix = std::vector<std::vector<int>>;

    Board(int size) : matrix(size, std::vector<int>(size)), n{size}, flags(size, std::vector<int>(size))
    {}

    void print_board() const {
        std::cout << "board:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << (*this)[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

    void invalidate_flags() {
        for (auto &v : flags) {
            for (auto &i : v) {
                i = false;
            }
        }
    }

    void move_at(Point p, Direction dir) {
        int &self = at(p);
        if (self == 0)
            return;
        Point shifted = p + directions[dir];
        if (is_valid(shifted)) {
            int &next = at(shifted);
            bool isnt_empty = next != 0;
            if (isnt_empty && self != next) {
                return;
            }
            if (flags[shifted.i][shifted.j] == true)
                return;
            next += self;

            self = 0;
            if (isnt_empty) {
                flags[shifted.i][shifted.j] = true;
                return;
            }
            move_at(shifted, dir);
        }
    }

    void foreach_up(Direction dir) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                move_at({i, j}, dir);
            }
        }
    }

    void foreach_down(Direction dir) {
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                move_at({i, j}, dir);
            }
        }
    }

    void foreach_left(Direction dir) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                move_at({i, j}, dir);
            }
        }
    }

    void foreach_right(Direction dir) {
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                move_at({i, j}, dir);
            }
        }
    }

    void board_move(Direction dir) {
        if (dir == UP)
            foreach_up(dir);
        else if (dir == DOWN)
            foreach_down(dir);
        else if (dir == LEFT)
            foreach_left(dir);
        else if (dir == RIGHT)
            foreach_right(dir);
        invalidate_flags();
    }

    bool is_valid(Point p) {
        return p.i >= 0 && p.j >= 0 && p.i < n && p.j < n;
    }

    int &at(Point p) {
        return (*this)[p.i][p.j];
    }

    int n;
    matrix flags;
};

int get_highest(const Board &b) {
    int highest = 0;
    for (const auto &v : b) {
        for (const auto i : v) {
            if (i > highest)
                highest = i;
        }
    }
    return highest;
}

int max_answer = 0;

// std::vector<Direction> moves;

void board_branch(const Board &board, int moves_left) {
    for (auto b : direction_enums) {
        Board board_b = board;
        board_b.board_move(b);

        // moves.push_back(b);

        if (moves_left <= 1) {
            int highest = get_highest(board_b);
            // std::cout << highest << '\n';

            // board_b.print_board();
            if (highest > max_answer)
                max_answer = highest;

            // std::cout << "moves: ";
            // for (const auto &sth : moves) {
            //     std::cout << sth << ' ';
            // }
            // std::cout << "\n";



            // moves.pop_back();
            continue;
        }

        board_branch(board_b, moves_left - 1);
        // moves.pop_back();
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;

    Board board_original(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> board_original[i][j];
        }
    }

    board_branch(board_original, 5);

// moves: 1 3 1 1 2 
// LEFT, RIGHT, UP, DOWN,
    // board_original.board_move(direction_enums[1]);
    // board_original.print_board();
    // board_original.board_move(direction_enums[3]);
    // board_original.print_board();
    // board_original.board_move(direction_enums[1]);
    // board_original.print_board();
    // board_original.board_move(direction_enums[1]);
    // board_original.print_board();
    // board_original.board_move(direction_enums[2]);

    // board_original.print_board();
    std::cout << max_answer << '\n';
}

