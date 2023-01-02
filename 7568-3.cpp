#include <iostream>
#include <vector>
using namespace std;
constexpr char WS = ' ';

bool comp(const pair<int,int> &lhs, const pair<int,int> &rhs) {
    if (lhs.first > rhs.first && lhs.second > rhs.second) return true;
    return false;
}
int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> vec;
    vec.reserve(N);
    for (int a, b, i = 0; i < N; ++i) {
        cin >> a >> b;
        vec[i] = pair(a, b);
    }
    for (int i = 0; i < N; ++i) {
        auto greater_cnt = 1;
        auto cur = vec[i];
        for (int j = 0; j < N; ++j) {
            if (comp(vec[j], cur)) ++greater_cnt;
        }
        cout << greater_cnt << WS;
    }
}
