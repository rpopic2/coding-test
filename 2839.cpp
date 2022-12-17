#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
constexpr int MAX_NUM = 5000;

int main()
{
    array<int, MAX_NUM> results{ 0 };
    results[3] = 1;
    results[5] = 1;
    int n_input;
    cin >> n_input;

    for (int i = 5 + 1; i <= n_input; ++i)
    {
        array<int, 2> a { results[i - 3], results[i - 5] };
        if (a[0] > a[1]) swap(a[0], a[1]);
        int &j = results[i];
        j = a[0] == 0 ? a[1] : a[0];
        if (j != 0) ++j;
    }
    int answer = results[n_input];
    if (answer == 0) answer = -1;

    cout << answer;
}
