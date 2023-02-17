#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;

constexpr char newl = '\n';

int at_or_zero(const vector<int> &vec, int at) {
    if (at < 0) return 0;
    auto size = vec.size();
    if (at >= size) return 0;
    return vec[at];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, K;
    cin >> N >> K;

    vector<int> cage(1'000'000, 0);
    int max_cage_index = 0;

    int _ice_amount, _pos;
    for (int i = 0; i < N; ++i) {
        cin >> _ice_amount >> _pos;
        cage[_pos] = _ice_amount;
        max_cage_index = max(max_cage_index, cage[_pos]);
    }


    int current_max = 0;
    int current_window = 0;


    for (int j = 0; j <= max_cage_index; ++j) {
        auto bear_index = j;
        auto left_idx = max(bear_index - K, 0);
        auto right_idx = min(bear_index + K, max_cage_index);

        current_window -= at_or_zero(cage, left_idx);
        current_window += at_or_zero(cage, right_idx);
        current_max = max(current_max, current_window);
    }

    cout << current_max << ::newl;
}
