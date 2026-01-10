#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using vec = std::vector<int>;
using mat = std::vector<vec>;
int n, m, v;

mat graph;

void dfs() {
    std::vector<char> visited(n+1);
    std::stack<int> q;
    q.push(v);

    while (!q.empty()) {
        auto top = q.top(); q.pop();
        if (visited[top])
            continue;
        visited[top] = true;
        std::cout << top << ' ';

        const auto &nodes = graph[top];
        for (int i = nodes.size() - 1; i >= 0; --i) {
        // for (int i = 0; i < nodes.size(); ++i) {
            int x = nodes[i];
            if (visited[x])
                continue;
            q.push(x);
        }
    }
    std::cout << '\n';
}

void bfs() {
    std::vector<char> visited(n+1);
    std::queue<int> q;
    q.push(v);

    while (!q.empty()) {
        auto top = q.front(); q.pop();
        if (visited[top])
            continue;
        visited[top] = true;
        std::cout << top << ' ';

        const auto &nodes = graph[top];
        // for (int i = nodes.size() - 1; i >= 0; --i) {
        for (int i = 0; i < nodes.size(); ++i) {
            int x = nodes[i];
            if (visited[x])
                continue;
            q.push(x);
        }
    }
    std::cout << '\n';
}

int main() {
    std::cin >> n >> m >> v;

    graph = mat(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (auto &g : graph) {
        std::sort(g.begin(), g.end());
    }

    dfs();
    bfs();
}

