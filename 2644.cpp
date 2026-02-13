#include <iostream>
#include <vector>

using vec = std::vector<int>;
using mat = std::vector<vec>;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    std::cin >> n;

    int no1, no2;
    std::cin >> no1 >> no2;

    mat graph(n+1);

    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    struct dfs_entry {
        int num; int depth;
    };
    std::vector<dfs_entry> q;
    std::vector<bool> visited(n+1);
    q.push_back({no1, 0});

    while (!q.empty()) {
        auto [num, depth] = q.back();
        q.pop_back();
        visited[num] = true;

        for (auto x : graph[num]) {
            if (visited[x])
                continue;
            q.push_back({x, depth + 1});
            if (x == no2) {
                std::cout << depth + 1;
                return 0;
            }
        }
            
    }
    std::cout << "-1";
}



