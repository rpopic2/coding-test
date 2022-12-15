#include <iostream>
#include <algorithm>
using namespace std;

constexpr int CNT_ALPHS = 'z' - 'a' + 1;
int main()
{
    int result[CNT_ALPHS];
    fill_n(result, CNT_ALPHS, -1);
    string s;
    cin >> s;
    for (int c, i = s.length(); i >= 0; --i)
    {
        c = s[i] - 'a';
        result[c] = i;
    }
    for (auto &i : result)
    {
        cout << i << ' ';
    }
}
