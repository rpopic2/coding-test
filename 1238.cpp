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
    using edge_t = ::edge;
    using adj_list_t = std::vector<std::vector<edge_t>>;

    graph(int num_nodes)
        : _adj_list(num_nodes + 1), _num_nodes(num_nodes) {}

    inline void add_edge(int start, int dest, int weight) {
        _adj_list[start].emplace_back(dest, weight);
    }

    int djikstra(int start, int dest) const;

private:
    adj_list_t _adj_list;
    int _num_nodes;
};

int graph::djikstra(int start, int dest) const {
    std::priority_queue<edge_t> pq;
    pq.emplace(start, 0);

    std::vector<bool> visited(_num_nodes + 1, false);

    while (!pq.empty()) {
        auto [cur_node, cur_weight] = pq.top();
        pq.pop();

        if (cur_node == dest)
            return cur_weight;

        if (visited[cur_node])
            continue;

        visited[cur_node] = true;

        for (const auto [node, weight] : _adj_list[cur_node]) {
            if (!visited[node])
                pq.emplace(node, cur_weight + weight);
        }
    }
    return 0;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int num_nodes, num_edges, dest;
    std::cin >> num_nodes >> num_edges >> dest;

    graph graph(num_nodes);

    int start, end, weight;
    for (int i = 0; i < num_edges; ++i) {
        std::cin >> start >> end >> weight;
        graph.add_edge(start, end, weight);
    }

    int max_student = 0;
    // should have iterating from 1 to num_nodes + 1...
    for (int i = 1; i < num_nodes + 1; ++i) {
        int way_go = graph.djikstra(i, dest);
        int way_back = graph.djikstra(dest, i);
        max_student = std::max(way_go + way_back, max_student);
    }

    std::cout << max_student << '\n';
}

