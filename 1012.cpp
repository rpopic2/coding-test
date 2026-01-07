#include <iostream>
#include <vector>

using vector = std::vector<int>;
using matrix = std::vector<vector>;

struct pair {
    int x;
    int y;

};

pair operator+(pair lhs, pair rhs) {
    return { lhs.x + rhs.x, lhs.y + rhs.y };
}

matrix field(50, vector(50));
std::vector<pair> q;
matrix visited(50, vector(50));
int m, n;

void mat_clear(matrix &mat) {
    for (auto &vec : mat)
        for (auto &i : vec)
            i = 0;
}

const pair DIRECTIONS[] = {
    { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 }
};

bool is_valid(pair p) {
    return p.x >= 0 && p.x < m
        && p.y >= 0 && p.y < n;
}

void dfs(pair coord) {
    q.clear();
    q.push_back(coord);

    while (!q.empty()) {
        pair top = q.back(); q.pop_back();
        visited[top.x][top.y] = true;

        for (const auto dir : DIRECTIONS) {
            pair next = top + dir;
            if (!is_valid(next))
                continue;
            if (visited[next.x][next.y])
                continue;
            if (field[next.x][next.y] == 0)
                continue;
            q.push_back(next);
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        mat_clear(field);
        mat_clear(visited);

        std::cin >> m >> n;

        int k;
        std::cin >> k;
        for (int j = 0; j < k; ++j) {
            int x, y;
            std::cin >> x >> y;
            field[x][y] = 1;
        }

        int count = 0;
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                pair target = {x, y};
                if (visited[x][y])
                    continue;
                if (field[x][y] == 0)
                    continue;
                dfs({x, y});
                ++count;
            }
        }
        std::cout << count << '\n';
    }
}

