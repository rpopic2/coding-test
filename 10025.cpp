#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;

constexpr char newl = '\n';

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, K;
    cin >> N >> K;

    map<int, int> cage;
    int max_cage_index = 0;

    int _ice_amount, _pos;
    for (int i = 0; i < N; ++i) {
        cin >> _ice_amount >> _pos;
        cage[_pos] = _ice_amount;
        max_cage_index = max(max_cage_index, cage[_pos]);
    }


    int current_max = 0;


    for (int j = 0; j < max_cage_index; ++j) {
        auto bear_index = j;
        auto left_idx = max(bear_index - K, 0);
        auto right_idx = min(bear_index + K, max_cage_index);

        auto accumulate = 0;
        cout << left_idx << ":" << right_idx << endl;
        for (int i = left_idx; i <= right_idx; ++i) {
            auto current_val = cage[i];
            if (current_val == 0) continue;
            accumulate += current_val;
            cout << current_val << endl;
        }
        current_max = max(current_max, accumulate);
    }

    cout << current_max << ::newl;
}
