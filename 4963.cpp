#include <iostream>
#include <vector>
#include <bitset>

using line = std::bitset<50>;
using map_t = std::vector<line>;

struct point {
    int x; int y;

    point operator+(point rhs) {
        return { x + rhs.x, y + rhs.y };
    }
};

map_t map(50);
int w, h;
std::vector<point> q(250);
int count;

const point directions[] = {
    {0, 1}, {0, -1}, {-1, 0}, {1, 0},
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};

bool is_valid(point p) {
    return p.x >= 0 && p.y >= 0
        && p.x < w && p.y < h;
}

void bfs(int x, int y) {
    q.clear();
    q.push_back({x, y});

    while (!q.empty()) {
        auto back = q.back();
        map[back.x][back.y] = 0;
        q.pop_back();

        for (auto dir : directions) {
            point next = back + dir;
            if (is_valid(next) && map[next.x][next.y] == 1) {
                q.push_back(next);
            }
        }
    }
    count += 1;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    while (true) {
        std::cin >> w >> h;
        if (w == 0)
            break;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                bool b;
                std::cin >> b;
                map[j][i] = b;
            }
        }

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (map[j][i])
                    bfs(j, i);
            }
        }
        std::cout << count << '\n';
        count = 0;
    }

}

