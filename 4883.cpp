#include <iostream>
#include <vector>

int min_cost;

class node
{
public:
    node(int _v, node *_pnext) : v{_v}, pnext{_pnext} {}
    int v;
    node *pnext;
    void explore(int _cur_cost);
};
void node::explore(int _cur_cost)
{
    _cur_cost += v;
    if (pnext != nullptr)
    {
        pnext->explore(_cur_cost);
    }
    else
    {
        min_cost = _cur_cost;
    }
}

int main()
{
    node n(1, nullptr);
    node p(2, nullptr);
    n.pnext = &p;

    n.explore(0);
    std::cout << min_cost;
}
