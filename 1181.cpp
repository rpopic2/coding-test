#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(string &lhs, string &rhs)
{
    if (lhs.length() > rhs.length()) return false;
    else if (lhs.length() < rhs.length()) return true;
    else return lhs < rhs;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<string> vec;
    vec.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), comp);
    for (const auto &s : vec)
    {
        auto ps = &s;
        if (*--ps != s) cout << s << '\n';
    }
}
