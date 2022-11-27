#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct line
{
    size_t x, y;
    line(){}
    line(int x_, int y_)
    {
        x = x_;
        y = y_;
    }
    size_t len()
    { 
        return y - x;
    }
    bool tryadd(const line* ln)
    {
        auto lnx = ln->x;
        auto lny = ln->y;
        cout << x << y << " " << lnx << lny << "\n";
        bool dirty = false;
        if (x <= lnx && y >= lnx)
        {
            y = max(y, lny);
            cout << "bigger " << y;
            dirty = true;
        }
        if (x <= lny && y >= lny)
        {
            x = min(x, lnx);
            dirty = true;
        }
        return dirty;
    }
};
int main()
{
    size_t N;
    cin >> N;

    vector<line*> ls;
    line lastln;
    for (int i = 0; i < N; i++)
    {
        size_t x, y;
        cin >> x >> y;
        line ln(x,y);
        bool b = lastln.tryadd(&ln);
        if(!b)
        {
            lastln = ln;
            ls.push_back(&ln);
        }
    }
    line r = *ls.at(0);
    cout << "result" << r.x << r.y;
}
