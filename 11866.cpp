#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, K;
    cin >> N >> K;

    vector<int> yosepus;
    yosepus.reserve(N);

    int next_remove = 0;

    for (int i = 1; i <= N; ++i) {
        next_remove += K;
        if (next_remove > N) {
            next_remove %= N;
        }
        cout << next_remove << endl;
        yosepus.push_back(next_remove);
    }

    cout << '<';
    for (int i = 0; i < N - 1; ++i) {
        cout << yosepus[i] << ", ";
    }
    cout << yosepus[N - 1] << '>' << '\n';

}
