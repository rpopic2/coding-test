#include <bitset>
#include <iostream>
#include <vector>
#include <queue>

using u32 = unsigned;
using i32 = signed;

struct point {
    i32 x; i32 y;
};

std::istream &operator>>(std::istream &is, point &p) {
    return is >> p.x >> p.y;
}
point operator+(point lhs, point rhs) {
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}
bool operator==(point lhs, point rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

std::vector<std::bitset<300>> visited(300);
void visited_clear(u32 size) {
    while (size--) {
        visited[size].reset();
    }
}

bool is_valid(u32 size, point p) {
    return p.x >= 0 && p.y >= 0
        && p.x < size && p.y < size;
}

const point directions[] = {
    {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
    {2, -1}, {1, -2}, {-1, -2}, {-2, -1},
};

struct bfs_entry {
    point p;
    u32 moves;
};

u32 bfs(u32 size, point src, point dst) {
    visited_clear(size);
    std::queue<bfs_entry> q;
    q.push({src, 0});

    while (!q.empty()) {
        auto [back, moves] = q.front();
        // printf("visitd %d, %d (%d)\n", back.x, back.y, moves);
        if (back == dst) {
            return moves;
        }
        q.pop();

        for (auto d : directions) {
            point target = back + d;
            if (!is_valid(size, target))
                continue;
            if (visited[target.x][target.y])
                continue;
            // printf("push %d, %d (%d)\n", target.x, target.y, moves+1);
            if (target == dst) {
                return moves + 1;
                break;
            }
            visited[target.x][target.y] = true;
            q.push({target, moves + 1});
        }
    }
    throw("not found"); // unreachable
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    u32 tc;
    std::cin >> tc;

    while (tc--) {
        u32 i;
        std::cin >> i;
        point src, dst;
        std::cin >> src >> dst;

        std::cout << bfs(i, src, dst) << '\n';
    }
    std::cout.flush();
    _Exit(0);
}

