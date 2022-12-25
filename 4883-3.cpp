#include <iostream>
#include <vector>
#include <optional>
using namespace std;

class tri_graph
{
public:
    tri_graph(const vector<int> *v);
    int traverse_from(int start_index);
private:
    vector<int> get_edges(int i);
    void fn(const int last_cost, const int index);
    const vector<int> *vec;
    int v_size;
    optional<int> min_cost;
};
tri_graph::tri_graph(const vector<int> *vec_)
{
    vec = vec_;
    v_size = vec->size();
}
vector<int> tri_graph::get_edges(int i)
{
        auto mod = i % 3;
        if (mod == 0) return {i+1,i+3,i+4};
        else if (mod == 1) return {i+1,i+2,i+3,i+4};
        else if (mod == 2) return {i+2,i+3};
        else throw;
}
int tri_graph::traverse_from(int start_index)
{
    fn(vec->at(start_index), start_index);
    return min_cost.value();
}
void tri_graph::fn(const int last_cost, const int index)
{
    if(index == v_size - 1)
    {
        if (min_cost.has_value())
        {
            if (min_cost.value() > last_cost) min_cost = last_cost;
        }
        else min_cost = last_cost;
    }
    for (const auto &e : get_edges(index))
    {
        if (e >= v_size) break;
        int cur_cost = last_cost + vec->at(e);
        if (!min_cost.has_value() || cur_cost < min_cost.value()) fn(cur_cost, e);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_no = 1;
    vector<int> v;
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0) return 0;
        v.clear();
        int v_size = n * 3 - 1;
        v.resize(v_size);
        for (int i = 0; i < v_size; ++i)
        {
            cin >> v[i];
        }
        tri_graph graph(&v);
        cout << test_no << ". " << graph.traverse_from(1)<< '\n';
        ++test_no;
        string dummy;
        cin >> dummy;
    }
}
