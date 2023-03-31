#include <iostream>
#include <vector>
#include <queue>

class graph {
public:
    graph(int size__) : size(size__), adj_list(size__) {}
    void add_adj(int node_a, int node_b) {
        adj_list[node_a].push_back(node_b);
        adj_list[node_b].push_back(node_a);
    }

    int bfs();

private:
    // a node, depth pair for bfs
    using pair = std::pair<int, int>;

    int size;
    std::vector<std::vector<int>> adj_list;
};

int num_country;

int graph::bfs() {
    std::queue<pair> q;
    q.push(pair(1, 0));

    std::vector<bool> visited(size, false);

    int visit_counter = 0;
    while(!q.empty()) {
        const auto [node, depth] = q.front();
        q.pop();
        if (depth == num_country - 1)
            return visit_counter;
        visited[node] = true;
        ++visit_counter;
        const auto &adj = adj_list[node];
        for (const auto &v : adj) {
            if (!visited[v])
                q.emplace(v, depth + 1);
        }
    }
    return visit_counter;
}


int main() {
    int num_tc;
    std::cin >> num_tc;

    while (num_tc--) {
        int num_planes;
        std::cin >> num_country >> num_planes;

        graph schedule(num_planes);
        int a, b;
        for (int i = 0; i < num_planes; ++i) {
            std::cin >> a >> b;
            schedule.add_adj(a, b);
        }
        std::cout << schedule.bfs() << '\n';
    }
}
