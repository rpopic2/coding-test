#include <iostream>
#include <vector>
#include <array>
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

inline int read_digit() {
    char c;
    do {
        c = cin.get();
    } while (c == '\n' || c == ' ');
    return c - '0';
}

bool is_valid(vertex v) {
    auto x = v.first;
    auto y = v.second;
    if (x < 0 || x >= N || y < 0 || y >= M) return false;
    if (maze[x][y] == 0) return false;
    return true;
}

//traverses from 0, 0 to N - 1, M - 1
//get length of the shortest path
int bfs_traverse() {
    queue<pair<vertex, int>> q; //queue of vertex and depth.
    q.push({{0, 0}, 1}); //x, y, depth
    while (!q.empty()) {
        auto [pos, depth] = q.front();
        auto [x, y] = pos;
        q.pop();
        if (maze[x][y] == 0) continue;
        maze[x][y] = 0;
        if (x == N - 1 && y == M - 1) return depth;  //destination node
        for (const auto &dir : directions) {
            vertex adjacent{dir.first + x, dir.second + y};
            if (is_valid(adjacent)) {
                q.push({adjacent, depth + 1});
            }
        }
    }
    return -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M;

    //fill in the maze from input
    maze = matrix(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            maze[i][j] = read_digit();
        }
    }

    cout << bfs_traverse() << ::endl;
}
