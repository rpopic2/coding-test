#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr char newl = '\n';

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // read input
    int N, K;
    cin >> N >> K;

    vector<int> cage(1'000'000, 0);
    int cage_size = 0;

    // read ice buckets from input
    for (int i = 0; i < N; ++i) {
        static int _ice_amount;
        static int _pos;
        cin >> _ice_amount >> _pos;
        cage[_pos] = _ice_amount;
        cage_size = std::max(cage_size, _pos + 1);
    }

    // returns the value at the given index, or 0 if out of bounds
    auto at_or_zero = [&](const int at) {
        if (at < 0) return 0;
        return cage[at];
    };

    int current_max = 0;

    // from zero width window, till the bear gets to the end of the cage
    for (int j = -K ; j <= cage_size - K - 1; ++j) {
        int left = j - K - 1;
        int right = j + K;

        static int current_window = 0;
        // move the window
        current_window -= at_or_zero(left);
        current_window += cage[right];

        // update current max
        current_max = max(current_max, current_window);
    }

    cout << current_max << ::newl;
}
