#include <iostream>
#include <vector>

class tri_graph
{
public:
    tri_graph(std::vector<int> *v);
    std::vector<std::vector<int>> edges;
private:
    std::vector<int> *nodes;
};
tri_graph::tri_graph(std::vector<int> *vec)
{
    nodes = vec;
    for (int i = 0, s = vec->size(); i < s; ++i)
    {
        auto mod = i % 3;
        std::vector<int> v;
        if (mod == 0) v = std::vector<int>{i+1, i+3, i+4};
        else if (mod == 1) v = std::vector<int>{i+1, i+2, i+3, i+4};
        else if (mod == 2) v = std::vector<int>{i+2, i+3};
        edges.push_back(v);
    }
}

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> v;
    for (int i = 0, c; i < size; ++i)
    {
        std::cin >> c;
        v.push_back(c);
    }
    tri_graph graph(&v);

    /*for (const auto &e : graph.edges[0])
    {
        if (e >= size) break;
        std::cout << e << ':';
        std::cout << v[e] << ' ';
    }*/

    int min_cost;
    for (const auto &e : graph.edges[0])
    {
        if (e >= size) break;
    }
}
