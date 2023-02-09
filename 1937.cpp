#include <iostream>
#include <vector>
#include <array>
#include <stack>
using namespace std;
using vertex = pair<int, int>;
using matrix = vector<vector<int>>;

constexpr array<vertex, 4> DIRECTIONS {
    vertex{1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

// global decl
int N;
int current_max = 0;
vector<vector<int>> memo;

// traverses the forest.
inline int traverse_forest(const matrix &forest, const vertex start) {
    matrix visited(N, vector<int>(N, 0));

    // validity checking
    auto is_valid = [&](const vertex pos, const vertex dest) {
        auto [x, y] = dest;
        if (x < 0 || x >= N || y < 0 || y >= N) {
            return false;
        }
        if (visited[x][y]) {
            return false;
        }
        if (forest[pos.first][pos.second] >= forest[x][y]) {
            return false;
        }
        return true;
    };

    // init
    static stack<pair<vertex, int>> s;
    s.push({start, 1});
    int max_depth = 0;

    // traversal
    while (true) {
        auto [pos, depth] = s.top();
        auto [x, y] = pos;
        s.pop();
        max_depth = max(depth, max_depth);
        visited[x][y] = true;
        auto &cur_memo = memo[x][y];
        cout << x << "," << y << ": " << depth << "m" << cur_memo << "  ";
        bool has_memo = false;
        if (cur_memo != 0) {
            auto memo_depth = cur_memo + depth - 1;
            memo[start.first][start.second] = memo_depth;
            max_depth = max(memo_depth, max_depth);
            has_memo = true;
        }
        bool is_end_node = true;
        for (const auto &dir : DIRECTIONS) {
            if (has_memo) break;
            vertex dest = {x + dir.first, y + dir.second};
            if (!is_valid(pos, dest)) continue;
            is_end_node = false;
            s.push({dest, depth + 1});
        }
        if (s.empty()) {
            memo[start.first][start.second] = max_depth;
            return max_depth;
        }
    }
    return -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    memo = vector<vector<int>>(N, vector<int>(N));
    
    // read forest from input
    matrix forest(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> forest[i][j];
        }
    }

    //for each vertex, do traversal
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            auto result = traverse_forest(forest, {i, j});
            current_max = max(current_max, result);
            cout << result << "/"<< current_max << endl << endl;
        }
    }
    cout << current_max << '\n';
}
