#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

constexpr int N = 9;
int main()
{
    array<int, N> a;
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    int *first = &a[0];
    int *max = max_element(a.begin(), a.end());
    cout << *max << '\n' << max - first + 1;
}
