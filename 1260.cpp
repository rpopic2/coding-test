#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using vec = std::vector<int>;
using mat = std::vector<vec>;

mat graph;
std::vector<char> visited;

void visited_clear() {
    for (auto &x : visited) {
        x = 0;
    }
}

void dfs(int v) {
    visited_clear();
    std::vector<int> q;
    q.push_back(v);
    visited[v] = true;

    while (!q.empty()) {
        auto back = q.back(); q.pop_back();
        std::cout << back << ' ';

        const auto &nodes = graph[back];
        for (int i = nodes.size() - 1; i >= 0; --i) {
            if (visited[i])
                continue;
            if (nodes[i] == 0)
                continue;
            visited[i] = true;
            q.push_back(i);
        }
    }
    std::cout << '\n';
}

void bfs(int v) {
    visited_clear();
    std::queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        auto back = q.back(); q.pop();
        std::cout << back << ' ';

        const auto &nodes = graph[back];
        for (int i = nodes.size() - 1; i >= 0; --i) {
            if (visited[i])
                continue;
            if (nodes[i] == 0)
                continue;
            visited[i] = true;
            q.push(i);
        }
    }
    std::cout << '\n';
}

int main() {
    int n, m, v;
    std::cin >> n >> m >> v;

    graph = mat(n + 1, vec(n + 1));
    visited = std::vector<char>(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    dfs(v);
    bfs(v);
}

