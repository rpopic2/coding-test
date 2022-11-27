#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct line
{
    size_t x, y;
    line(size_t x_, size_t y_)
    {
        x = x_;
        y = y_;
    }
};
bool sorter(line ln1, line ln2)
{
    if(ln1.x == ln2.x) return ln1.y > ln2.y;
    else return ln1.x > ln2.x;
}

int main()
{
    size_t N;
    cin >> N;

    vector<line> v;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        line ln(x, y);
        v.push_back(ln);
    }
    sort(v.begin(), v.end(), sorter);
    
    size_t cx, cy, r;
    cx = 0;
    cy = 0;
    r = 0;
    for (auto ln : v)
    {
        auto x = ln.x;
        auto y = ln.y;
        if (y < cy) continue;
        if (x <= cy) cy = y;
        else if (x > cy)
        {
            r += cy - cx;
            cx = x;
            cy = y;
        }
    }
    r += cy - cx;
    cout << r;
}

