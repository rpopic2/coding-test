#include <iostream>
#include <vector>
#include <array>
using namespace std;
using vertex = pair<int, int>;
using matrix = vector<vector<int>>;
class bamboo {
constexpr array<vertex, 4> DIRECTIONS {
    vertex{1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

// globals
int N;
int current_max = 0;
int memo[502][502];

// dp + dfs
inline int traverse_forest(const matrix &forest, const vertex start) {

    auto [x, y] = start;
    auto &current_memo = memo[x][y];
    if (current_memo != 0) return current_memo;

    // 갈 수 있는 곳인지 확인, 이동하는 곳이 현재보다 작은지 확인
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

    // 주변 네 칸 중 가장 큰 칸을 찾기
    int adjacent_max = 0;
    for (const auto &dir : DIRECTIONS) {
        vertex dest = {x + dir.first, y + dir.second};
        if (!is_valid(start, dest)) {
            continue;
        }
        int at_dest = traverse_forest(forest, dest);
        adjacent_max = max(adjacent_max, at_dest);
    }

    // 주변에 갈 수 없는 곳이 없으면 adjacent_max가 1이 됨.
    // 주변에 가장 큰 곳 + 1이 이동할 수 있는 최댓값임.
    // 한 노드에서 다른 노드로 이동할 수 있는 곳이 하나뿐이고, 그게 주변 네 노드 중 가장 큰 노드임.
    current_memo = adjacent_max + 1;
    return current_memo;
}

void eat_bamboo() {}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;



    // 숲 읽어들이기
    matrix forest(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> forest[i][j];
        }
    }

    // 모든 칸에서 dfs 시작, 최댓값 찾기
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            auto result = traverse_forest(forest, {i, j});
            current_max = max(current_max, result);
        }
    }

    cout << current_max << '\n';
}

() {
    panda p;

    string cmd:
    cin >> cmd;

    p.cmd;
}
