#include <iostream>
#include <queue>

using i64 = long long;
using i32 = int;

struct bfs_entry {
    i64 num;
    i32 depth;
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    i64 a, b;
    std::cin >> a >> b;

    std::queue<bfs_entry> q;
    // std::vector<bool> visited(1'000'000'001);
    q.push({a, 1});
    // visited[a] = true;

    while (!q.empty()) {
        auto [num, depth] = q.front();
        q.pop();
        if (num == b) {
            std::cout << depth << '\n';
            return 0;
        }
        auto add1 = num * 10 + 1;
        if (add1 <= b) {
            q.push({add1, depth + 1});
            // visited[add1] = true;
        }
        auto mul2 = num * 2;
        if (mul2 <= b) {
            q.push({mul2, depth + 1});
            // visited[mul2] = true;
        }
    }
    std::cout << "-1\n";
}

