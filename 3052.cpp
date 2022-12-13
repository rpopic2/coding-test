#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<int> v;
    for (int i = 0, c; cin >> c; ++i)
    {
        v.insert(c % 42);
    }
    cout << v.size();
}
