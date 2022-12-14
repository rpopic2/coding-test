#include <iostream>
#include <array>
using namespace std;
constexpr array<int, 2> T = {24, 60};
void subtract(array<int, 2> &a, int index, int amount);
int main()
{
    array<int, 2> op = {0, 45};
    array<int, 2> t;
    for (int i = 0, c; cin >> t[i]; ++i) { }
    for (int i = 0; i < 2; ++i)
    {
        subtract(t, i, op[i]);
    }
    cout << t[0] << ' ' << t[1];
}
void subtract(array<int, 2> &a, int index, int amount)
{
    a[index] -= amount;
    if (a[index] < 0)
    {
        a[index] += T[index];
        if (index <= 0) return;
        subtract(a, index - 1, 1);
    }
}
