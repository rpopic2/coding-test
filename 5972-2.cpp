#include <iostream>
#include <vector>
#include <queue>

struct edge {
    int node, weight;

    edge(int node__, int weight__)
        : node(node__), weight(weight__) {}

    bool operator<(const edge &rhs) const noexcept {
        return weight > rhs.weight;
    }
};

class graph {
public:
    graph(int num_nodes__) :
        adj_list(num_nodes__ + STARTS_FROM), num_nodes(num_nodes__)
    , end_node(num_nodes) {}

    void add_edge(int src_node, int dest_node, int weight) {
        adj_list[src_node].emplace_back(dest_node, weight);
        adj_list[dest_node].emplace_back(src_node, weight);
    }

    int dijkstra();

private:
    std::vector<std::vector<edge>> adj_list;
    int num_nodes;
    int end_node;
    constexpr static int STARTS_FROM = 1;
};

// the dijkstra's algorithm
int graph::dijkstra() {
    std::vector<bool> visited(num_nodes + STARTS_FROM, false);
    std::priority_queue<edge> pq;
    pq.emplace(STARTS_FROM, 0); // distance to START_NODE is 0

    while (!pq.empty()) {
        auto [cur_node, cur_weight] = pq.top();
        pq.pop();

        // return early if arrived at the end node
        if (cur_node == end_node)
            return cur_weight;

        if (visited[cur_node])
            continue;

        visited[cur_node] = true;
        // push unvisited adjacent nodes
        for (const auto &[dest, weight] : adj_list[cur_node]) {
            if (!visited[dest])
                pq.emplace(dest, cur_weight + weight);
        }
    }
    return -1;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int nodes_count, edges_count;
    std::cin >> nodes_count >> edges_count;

    // Create adjacency list from input
    graph graph(nodes_count);

    for (int i = 0; i < edges_count; ++i) {
        int node_a, node_b, weight;
        std::cin >> node_a >> node_b >> weight;
        graph.add_edge(node_a, node_b, weight);
    }

    std::cout << graph.dijkstra() << '\n';
}

