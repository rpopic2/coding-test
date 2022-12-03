#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

constexpr int COUNT_DICES = 3;
int main()
{
    array<int, COUNT_DICES> a;
    for (int i = 0; i < COUNT_DICES; ++i)
    {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }

    int* v = unique(a.begin(), a.end());
    auto d = distance(a.begin(), v);
    cout << d;
}
