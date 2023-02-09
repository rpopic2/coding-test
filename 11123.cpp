#include <iostream>
#include <vector>
#include <array>
#include <stack>
using namespace std;

constexpr char GRASS = '.';
constexpr array<pair<int, int>, 4> DIRECTIONS = {
    pair<int, int>{0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

// whether given start point is a flock of sheeps or not
inline void dfs_remove_flock(vector<string> &matrix, const pair<int, int> start, const int H, const int W) {
    // validity checker
    auto is_valid = [&](pair<int, int> vertex) {
        auto [x, y] = vertex;
        if (x < 0 || x >= H || y < 0 || y >= W) return false;
        if (matrix[x][y] == GRASS) return false;
        return true;
    };

    // init
    static stack<pair<int ,int>> s;
    s.push(start);

    // dfs traversal
    while (!s.empty()) {
        auto [x, y] = s.top();
        s.pop();
        matrix[x][y] = GRASS;
        for (const auto &dir : DIRECTIONS) {
            pair<int, int> neighbour{dir.first + x, dir.second + y};
            if (!is_valid(neighbour)) continue;
            else s.push(neighbour);
        }

    }
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
        vector<string> matrix(H, string(W, GRASS));
        for (auto &line : matrix) {
            cin >> line;
        }

        // for each vertex, traverse the graph
        int sheep_flocks = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (matrix[i][j] == GRASS) continue;
                sheep_flocks += 1;
                dfs_remove_flock(matrix, {i, j}, H, W);
            }
        }
        cout << sheep_flocks << '\n';
    }
}

// pitfalls i've gone through:
// 1. using bfs will cause memory exeed
// 2. checking for visited will slow down by 200ms. removing sheeps if checked is faster
// 3. using std::string instead of std::vector<char> is simpler if input does not contain whitespaces
// 4. when using std::vector<std::string>, calling "fill-in constructor"; when initialising std::string inside std::vector, is faster than not calling it, because c++ would have to keep re-allocating the std::vector if string size is unknown.
