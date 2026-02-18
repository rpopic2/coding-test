#include <iostream>
#include <vector>

using vec = std::vector<int>;
using map_t = std::vector<vec>;

map_t map;
int n;

struct point {
    int x; int y;
};
point operator +(point lhs, point rhs) {
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

const point directions[] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
};

bool is_valid(point p) {
    return p.x >= 0 && p.y >= 0
        && p.x < n && p.y < n;
}

int bfs(point start, int marker) {
    if (map[start.x][start.y] != -1)
        return 0;

    std::vector<point> q;
    q.push_back(start);
    map[start.x][start.y] = marker;
    int marked = 1;

    while (!q.empty()) {
        auto cur = q.back();
        q.pop_back();

        for (auto d : directions) {
            point next = cur + d;
            if (!is_valid(next))
                continue;
            if (map[next.x][next.y] != -1)
                continue;
            map[next.x][next.y] = marker;
            q.push_back(next);
            marked += 1;
        }
    }
    return marked;
}

int main() {
    std::cin >> n;

    map = map_t(n, vec(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char x;
            std::cin >> x;
            map[i][j] = x == '1' ? -1 : 0;
        }
    }

    int num_danji = 0;
    vec answers;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int found = bfs({i, j}, num_danji + 1);
            if (found) {
                num_danji += 1;
                answers.push_back(found);
            }
        }
    }

    std::sort(answers.begin(), answers.end());

    std::cout << num_danji << '\n';
    for (int x : answers) {
        std::cout << x << '\n';
    }
}

