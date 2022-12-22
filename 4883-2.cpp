#include <iostream>
#include <vector>
#include <optional>
#include <memory>
using namespace std;
constexpr streamsize BIG_NUM = 1 << 16;

class tri_graph
{
public:
    void init(vector<int> *v);
    int traverse_from(int start_index);
private:
    void fn(const int last_cost, const int index);
    vector<int> *vec;
    int v_size;
    optional<int> min_cost;
    unique_ptr<vector<vector<int>>> edges;
};
void tri_graph::init(vector<int> *vec_)
{
    vec = vec_;
    edges = make_unique<vector<vector<int>>>();
    v_size = vec->size();
    for (int i = 0; i < v_size; ++i)
    {
        auto mod = i % 3;
        vector<int> v;
        if (mod == 0) v = vector<int>{i+1, i+3, i+4};
        else if (mod == 1) v = vector<int>{i+1, i+2, i+3, i+4};
        else if (mod == 2) v = vector<int>{i+2, i+3};
        edges->push_back(v);
    }
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
    for (const auto &e : (*edges.get())[index])
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
    while (true)
    {
        tri_graph graph;
        int n;
        cin >> n;
        if (cin.eof()) return 0;
        vector<int> v;
        int v_size = n * 3 - 1;
        for (int i = 0, c; i < v_size; ++i)
        {
            cin >> c;
            v.push_back(c);
        }
        cin.ignore(BIG_NUM, '0');
        graph.init(&v);
        cout << test_no << ". " << graph.traverse_from(1)<< '\n';
        ++test_no;
    }
}
