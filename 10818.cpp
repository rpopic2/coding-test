#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> v;
    for (; N > 0; --N)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    auto minmax = minmax_element(v.begin(), v.end());
    cout << *minmax.first << ' ' << *minmax.second;
}
