#include <iostream>
#include <vector>
using namespace std;
constexpr char WS = ' ';
typedef pair<int, int> ipair;
typedef vector<ipair> vec_pair;

inline bool comp(const ipair &lhs, const ipair &rhs) {
    if (lhs.first > rhs.first && lhs.second > rhs.second) return true;
    return false;
}
inline void solve(const int N, const vec_pair vec) {
    for (int i = 0; i < N; ++i) {
        auto greater_cnt = 0;
        auto cur = vec[i];
        for (int j = 0; j < N; ++j) {
            if (comp(vec[j], cur)) ++greater_cnt;
        }
        cout << greater_cnt + 1 << WS;
    }
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
    solve(N, vec);
}
