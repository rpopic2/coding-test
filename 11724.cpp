#include <iostream>
#include <vector>

using vec = std::vector<int>;
using mat = std::vector<vec>;
mat graph;

std::vector<bool> visited;

void dfs(int start) {
    vec q;
    q.push_back(start);

    while (!q.empty()) {
        auto top = q.back(); q.pop_back();
        visited[top] = true;

        const auto &nodes = graph[top];
        for (auto x : nodes) {
            if (visited[x])
                continue;
            q.push_back(x);
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;

    graph = mat((n + 1));
    visited = std::vector<bool>(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int answer = 0;
    while (true) {
        int target = 0;
        for (int i = 1; i <= n; ++i) {
            if (visited[i] == false) {
                target = i;
                break;
            }
        }
        if (!target)
            break;
        // printf("target %d\n", target);
        dfs(target);
        ++answer;
    }
    std::cout << answer;
}

