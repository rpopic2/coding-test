#include <iostream>
using namespace std;
constexpr int H = 24;
constexpr int M = 60;
int main()
{
    int h, m;
    cin >> h >> m;
    m -= 45;
    if (m < 0)
    {
        m += M;
        --h;
    }
    if (h < 0)
    {
        h += H;
    }
    cout << h << ' ' << m;
}
