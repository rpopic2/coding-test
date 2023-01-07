#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

bool comp(const pair<int, int> &lhs, const pair<int, int> &rhs) {
    if (lhs.first > rhs.first) return false;
    else if (lhs.first < rhs.first) return true;
    else if (lhs.second > rhs.second) return false;
    else return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int>> vec;
    vec.resize(N);
    for (int a, b, i = 0; i < N; ++i) {
        cin >> a >> b;
        vec[i] = {a, b};
    }
    sort(vec.begin(), vec.end(), comp);
    for (const auto &p : vec) {
        cout << p.first << ' ' << p.second << '\n';
    }
}
