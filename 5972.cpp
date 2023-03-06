#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int nodes_count, edges_count;
    std::cin >> nodes_count >> edges_count;

    std::vector<int> nodes(nodes_count, 0);

    using edge_pair = std::pair<int, int>;
    using adj_matrix = std::vector<std::vector<edge_pair>>;

    adj_matrix adj_list(edges_count, std::vector<edge_pair>());

    int node_a, node_b, cost_edge;
    for (int i = 0; i < edges_count; ++i) {
        std::cin >> node_a >> node_b >> cost_edge;
        adj_list[node_a].emplace_back(node_b, cost_edge);
        adj_list[node_b].emplace_back(node_a, cost_edge);
    }

    std::queue<edge_pair> q;
    q.emplace(1, 0);

    int total_cost = 0;

    while (!q.empty()) {

        auto [node, cur_cost] = q.front(); q.pop();


        if (node == nodes_count)
            break;

        nodes[node] = -1;
        auto &adj = adj_list[node];

        int node_to_go = 0;
        int min = 1 << 17;
        for (const auto &[n, cost] : adj) {
            if (nodes[n] == -1)
                continue;
            else if (cost >= min)
                continue;
            node_to_go = n;
            min = cost;
        }

        cur_cost += min;

        q.emplace(node_to_go, cur_cost);
        total_cost = cur_cost;



    }

    std::cout << total_cost;

}
