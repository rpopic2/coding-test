#include <iostream>
#include <vector>
#include <queue>
#include <limits>

constexpr static auto I32_MAX = std::numeric_limits<int>::max();
constexpr static int START_NODE = 1;

using edge = std::pair<int, int>;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int nodes_count;
    int edges_count;
    std::cin >> nodes_count >> edges_count;

    std::vector<std::vector<edge>> adj_list(nodes_count + 1);

    {
        int node_a, node_b;
        int cost;

        for (int i = 0; i < edges_count; ++i) {
            std::cin >> node_a >> node_b;
            std::cin >> cost;
            adj_list[node_a].emplace_back(node_b, cost);
            adj_list[node_b].emplace_back(node_a, cost);
        }
    }

    std::vector<int> shortest_distances(nodes_count + 1, I32_MAX);

    std::priority_queue<edge> pq;
    pq.emplace(START_NODE, 0); // distance to START_NODE is 0
    shortest_distances[START_NODE] = 0;

    while (!pq.empty()) {
        auto [cur_node, cur_cost] = pq.top();
        pq.pop();

        if (cur_cost > shortest_distances[cur_node])
            continue;

        for (const auto &[dest, cost] : adj_list[cur_node]) {
            auto &shortest_to_dest = shortest_distances[dest];
            auto &shortest_to_cur = shortest_distances[cur_node];

            if (shortest_to_dest > shortest_to_cur + cost) {
                shortest_to_dest = shortest_to_cur + cost;
                pq.emplace(dest, shortest_distances[dest]);
            }
        }
    }

    std::cout << shortest_distances[nodes_count] << '\n';
}

