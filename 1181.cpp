#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(string &lhs, string &rhs)
{
    if (lhs.size() > rhs.size()) return false;
    else if (lhs.size() < rhs.size()) return true;
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
    auto unique_end = unique(vec.begin(), vec.end());
    vec.resize(distance(vec.begin(), unique_end));
    for (const auto &s : vec)
    {
        cout << s << '\n';
    }
}
