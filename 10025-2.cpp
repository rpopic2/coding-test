#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;

constexpr char newl = '\n';
int cage_size = 0;

int at_or_zero(const vector<int> &vec, int at) {
    if (at < 0) return 0;
    if (at >= cage_size) return 0;
    //cout << endl << vec[at] << endl << endl;
    return vec[at];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, K;
    cin >> N >> K;

    vector<int> cage(1'000'000, 0);

    int _ice_amount, _pos;
    for (int i = 0; i < N; ++i) {
        cin >> _ice_amount >> _pos;
        cage[_pos] = _ice_amount;
        cage_size = max(cage_size, _pos + 1);
    }

    int current_max = 0;
    int current_window = 0;


    for (int j = -K * 2; j <= cage_size; ++j) {
        auto bear_index = j;
        auto delete_idx = bear_index - K - 1;
        auto add_idx = bear_index + K;

        current_window -= at_or_zero(cage, delete_idx);
        current_window += at_or_zero(cage, add_idx);
        //cout << at_or_zero(cage, delete_idx) << '?' << at_or_zero(cage, add_idx);
        //cout << delete_idx << ':' << add_idx << '=' << current_window << endl;
        current_max = max(current_max, current_window);
    }

    cout << current_max << ::newl;
}
