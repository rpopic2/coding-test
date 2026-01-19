#include <iostream>
#include <queue>
#include <vector>

enum cell {
    EMPTY = -1, NOT_RIPE = 0, RIPE = 1
};

using i8 = int;
using vec = std::vector<i8>;
using mat = std::vector<vec>;

struct pair {
    int x, y;
};

pair operator+(pair lhs, pair rhs) {
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

int m, n;
mat storage;
std::queue<pair> q;


const pair DIR[] = {
    { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 }
};

bool is_valid(int x, int y) {
    return x >= 0 && y >= 0
        && x < n && y < m;
}

void bfs() {
    while (!q.empty()) {
        auto front = q.front(); q.pop();
        auto current = storage[front.x][front.y];
        for (auto d : DIR) {
            auto pos = front + d;
            if (!is_valid(pos.x, pos.y))
                continue;
            auto &target = storage[pos.x][pos.y];
            if (target == 0) {
                target = current + RIPE;
                q.push(pos);
            }
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cin >> m >> n;

    storage = mat(n, vec(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> storage[i][j];
            if (storage[i][j] == RIPE)
                q.push({i, j});
        }
    }
    bfs();

    int max = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (storage[i][j] == NOT_RIPE) {
                std::cout << "-1\n";
                return 0;
            }
            max = std::max(max, storage[i][j]);
        }
    }
    std::cout << max - 1<< '\n';
}
