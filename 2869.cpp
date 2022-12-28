#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int mv_day, mv_night, height;
    cin >> mv_day >> mv_night >> height;
    int ans = (1 + (height - mv_day) / (mv_day - mv_night));
    if ((height - mv_day) % (mv_day - mv_night))
    {
        ++ans;
    }
    cout << ans;
}
