#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

constexpr int DICES = 3;
int main()
{
    array<int, DICES> a;
    for (int i = 0; i < DICES; ++i)
    {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    sort(a.begin(), a.end());

    auto answer = 0;
    if(a[1] == a[0] && a[1] == a[2]) answer = 10000 + a[1] * 1000;
    else if(a[1] == a[0] || a[1] == a[2]) answer = 1000 + a[1] * 100;
    else answer = a[2] * 100;

    cout << answer;
}
