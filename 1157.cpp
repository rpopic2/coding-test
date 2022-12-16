#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string word;
    cin >> word;

    unordered_map<char, int> map;
    for (auto &c : word)
    {
        ++map[toupper(c)];
    }

    pair<char, int> max;
    for (auto &p : map)
    {
        if (p.second <= max.second) continue;
        max = p;
    }

    for (auto &p : map)
    {
        if (p.second == max.second && p.first != max.first)
        {
            max = make_pair('?', -1);
        }
    }

    char answer = toupper(max.first);
    cout << answer;
}
