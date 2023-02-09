#include <iostream>
#include <vector>
#include <array>
#include <stack>
using namespace std;

constexpr char GRASS = '.';
constexpr array<pair<int, int>, 4> DIRECTIONS = {
    pair<int, int>{0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

bool dfs_traverse(vector<vector<char>> &matrix, const pair<int, int> start, const int H, const int W) {
    // short circuiting. if starting point is a grass, return immediately.
    if (matrix[start.first][start.second] == GRASS) return false;

    // validity checker
    vector<vector<bool>> visited(H, vector<bool>(W));
    auto is_valid = [&](pair<int, int> vertex) {
        auto [x, y] = vertex;
        if (x < 0 || x >= H || y < 0 || y >= W) return false;
        if (matrix[x][y] == GRASS) return false;
        return true;
    };

    // init
    stack<pair<int ,int>> s;
    s.push(start);

    // dfs traversal
    while (!s.empty()) {
        auto [x, y] = s.top();
        s.pop();
        matrix[x][y] = GRASS;
        for (const auto &dir : DIRECTIONS) {
            pair<int, int> neighbour{dir.first + x, dir.second + y};
            if (is_valid(neighbour)) {
                s.push(neighbour);
            }
        }

    }
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;

    // for each test cases
    while (T--) {
        int H, W;
        cin >> H >> W;

        // read the matrix in
        vector<vector<char>> matrix(H, vector<char>(W));
        for (int i = 0; i < H; ++i) {
            string line;
            cin >> line;
            for (int j = 0; j < W; ++j) {
                matrix[i][j] = line[j];
            }
        }
        int sheep_flocks = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                sheep_flocks += dfs_traverse(matrix, {i, j}, H, W);
            }
        }
        // traverse the graph
        cout << sheep_flocks << '\n';
    }
}
