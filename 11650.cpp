#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct pos {
    int x, y;
};

bool comp(const pos &lhs, const pos &rhs) {
    if (lhs.x > rhs.x) return false;
    else if (lhs.x < rhs.x) return true;
    else if (lhs.y > rhs.y) return false;
    else return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pos> vec;
    vec.resize(N);
    for (int a, b, i = 0; i < N; ++i) {
        cin >> a >> b;
        vec[i] = {a, b};
    }
    sort(vec.begin(), vec.end(), comp);
    for (const auto &p : vec) {
        cout << p.x << ' ' << p.y << '\n';
    }
}
