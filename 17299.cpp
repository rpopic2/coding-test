#include <iostream>
#include <array>
using namespace std;
constexpr int N_MAX = 1'000'000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    array<int, N_MAX + 1> cnts, vec;
    cin >> N;
    for (int c, i = 0; i < N; ++i) {
        cin >> c;
        ++cnts[c];
        vec[i] = c;
    }
    for (int i = 0; i < N; ++i) {
        auto cur = vec[i];
        auto ccnt = cnts[cur];
        int ngf = -1;
        for (int j = N - 1; j > i; --j) {
            auto nextto = vec[j];
            auto comp = cnts[nextto];
            if (comp > ccnt) ngf = nextto;
        }
        cout << ngf;
    }
}
