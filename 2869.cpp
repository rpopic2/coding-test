#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int mv_day, mv_night, height;
    cin >> mv_day >> mv_night >> height;
    int result = 1 + height / (mv_day - mv_night);
    int mod = height % (mv_day - mv_night);
    if (mod == 0)
    {
        result -= mv_day;
    }
    cout << result;
}
