#include <iostream>
#include <vector>
#include <array>
using namespace std;
using vertex = pair<int, int>;
using matrix = vector<vector<int>>;

constexpr array<vertex, 4> DIRECTIONS {
    vertex{1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

// globals
int N;
int current_max = 0;
int memo[502][502];

// traverses the forest. dp + dfs.
inline int traverse_forest(const matrix &forest, const vertex start) {

    auto [x, y] = start;
    auto &current_memo = memo[x][y];
    if (current_memo != 0) return current_memo;

    // validity checking. this is a directed graph where childen are greater than parent.
    auto is_valid = [&](const vertex pos, const vertex dest) {
        auto [x, y] = dest;
        if (x < 0 || x >= N || y < 0 || y >= N) {
            return false;
        }
        if (forest[pos.first][pos.second] >= forest[x][y]) {
            return false;
        }
        return true;
    };

    // get the greatest adjacent node
    int adjacent_max = 0;
    for (const auto &dir : DIRECTIONS) {
        vertex dest = {x + dir.first, y + dir.second};
        if (!is_valid(start, dest)) {
            continue;
        }
        int at_dest = traverse_forest(forest, dest);
        adjacent_max = max(adjacent_max, at_dest);
    }

    current_memo = adjacent_max + 1;
    return current_memo;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    
    // read forest from input
    matrix forest(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> forest[i][j];
        }
    }

    //for each vertex, traverse and update max number.
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            auto result = traverse_forest(forest, {i, j});
            current_max = max(current_max, result);
        }
    }

    cout << current_max << '\n';
}
