#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> vec;
    int count;
    cin >> count;
    vec.resize(count);
    for (int i = count; i--;)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    string buf;
    for (const auto &i : vec)
    {
        buf += to_string(i) + '\n';
    }
    cout << buf;
}
