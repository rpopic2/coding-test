#include <iostream>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
using namespace std;
using vertex = pair<int, int>;
using matrix = vector<vector<int>>;

constexpr auto endl = '\n';
constexpr array<vertex, 4> directions {
    vertex{0, -1}, {-1, 0}, {0, 1}, {1, 0}
};

int N, M;
matrix maze;
matrix visited;

bool is_valid(vertex v) {
    auto x = v.first;
    auto y = v.second;
    if (x < 0 || x >= N || y < 0 || y >= M) return false;
    if (visited[x][y] == 1) return false;
    return true;
}

int bfs_traverse() {
    int count = 1;
    queue<vertex> q;
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty()) {
        auto _pair = q.front();
        auto x = _pair.first;
        auto y = _pair.second;
        q.pop();
        count += 1;
        if (x == N - 1 && y == M - 1) return count;
        cout << x << ", " << y << ::endl;
        for (const auto &dir : directions) {
            vertex adjacent{dir.first + x, dir.second + y};
            if(is_valid(adjacent)) {
                q.push(adjacent);
                visited[adjacent.first][adjacent.second] = true;
            }
        }
    }
    return count;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M;
    maze = matrix(N, vector<int>(M));
    visited = matrix(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            auto c = cin.get();
            if (c == '\n') continue;
            maze[i][j] = c - '0';
        }
    }
    cout << bfs_traverse() << ::endl;
}
