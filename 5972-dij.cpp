#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int node_count;
    int edge_count;
    std::cin >> node_count >> edge_count;

    using pair = std::pair<int, int>;
    std::vector<std::vector<pair>> adj_list(node_count);

    
    int node_a, node_b;
    int edge_cost;
    for (int i = 0; i < edge_count; ++i) {
        std::cin >> node_a >> node_b;
        std::cin >> edge_cost;
        adj_list[node_a].push_back(pair(node_b, edge_cost));
        adj_list[node_b].emplace_back(node_a, edge_cost);
    }



}
