#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct line
{
    long long x, y;
    line(long long x_, long long y_)
    {
        x = x_;
        y = y_;
    }
};
bool sorter(line ln1, line ln2)
{
    if(ln1.x == ln2.x) return ln1.y < ln2.y;
    else return ln1.x < ln2.x;
}

int main()
{
    int N;
    cin >> N;

    vector<line> v;
    for (int i = 0; i < N; i++)
    {
        long long x, y;
        cin >> x >> y;
        line ln(x, y);
        v.push_back(ln);
    }
    sort(v.begin(), v.end(), sorter);

    long long cx, cy, r;
    auto first = v.at(0);
    cx = first.x;
    cy = first.y;
    r = 0;
    for (int i = 1; i < v.size(); i++)
    {
        auto ln = v.at(i);
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

