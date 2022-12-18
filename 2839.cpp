#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
constexpr int MAX_NUM = 5000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_input;
    cin >> n_input;
    if (n_input == 3 || n_input == 5)
    {
        cout << 1;
        return 0;
    }
    if (n_input == 4 || n_input == 7)
    {
        cout << -1;
        return 0;
    }
    array<int, MAX_NUM> results{ 0 };
    results[3] = 1;
    results[5] = 1;

    for (int i = 5 + 1; i <= n_input; ++i)
    {
        array<int, 2> a { results[i - 3], results[i - 5] };
        sort(a.begin(), a.end());
        int &j = results[i];
        j = a[0] == 0 ? a[1] : a[0];
        if (j != 0) ++j;
    }
    int answer = results[n_input];
    if (answer == 0) answer = -1;

    cout << answer;
}
