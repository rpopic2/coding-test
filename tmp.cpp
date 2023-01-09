#include <iostream>
#include <array>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int N_MAX = 1'000'000;
array<int, N_MAX + 1> f;
vector<int> arr;
set<int> s;
bool comp(const int &lhs, const int &rhs) {
    return f[lhs] > f[rhs];
}
bool compmin(const int &lhs, const int &rhs) {
    return f[lhs] < f[rhs];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    arr.resize(N);
    for (int c, i = 0; i < N; ++i) {
        cin >> c;
        ++f[c];
        arr[i] = c;
        s.insert(c);
    }
    int max = *max_element(s.begin(), s.end(), compmin);
    string buf;
    for (int i = 0; i < N - 1; ++i) {
        auto cur = arr[i];
        if (cur == max) {
            buf += "-1 ";
            continue;
        }
        auto ccnt = f[cur];
        int ngf = -1;
        for (int j = i + 1; j < N; ++j) {
            auto nextto = arr[j];
            auto comp = f[nextto];
            if (comp > ccnt)
            {
                ngf = nextto;
                break;
            }
        }
        buf += to_string(ngf) + ' ';
    }
    cout << buf << "-1";
}

