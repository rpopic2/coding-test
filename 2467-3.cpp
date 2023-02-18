#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

constexpr char ws = ' ';
constexpr char newl = '\n';
constexpr auto I32MAX = numeric_limits<int>::max();

int main() {
    int N;
    cin >> N;

    vector<int> liquids(N);
    for (int i = 0; i < N; ++i) {
        cin >> liquids[i];
    }

    int best_sum = numeric_limits<int>::max();
    pair<int, int> best_pair;

    auto start = liquids.cbegin();
    for (const auto &i : liquids) {
        auto ub = upper_bound(++start, liquids.cend(), i * -1);
        int sum = ub == liquids.end() ? I32MAX : *ub + i;
        if (::abs(sum) < best_sum && ub != liquids.end()) {
            best_sum = sum;
            best_pair = {i, *ub};
            cout << i << ::ws << *ub << newl;
            cout << sum << endl;
        }
        int sum2 = *--ub + i;
        if (::abs(sum2) < best_sum && ub != liquids.end()) {
            best_sum = sum2;
            best_pair = {i, *ub};
            cout << i << ::ws << *ub << newl;
            cout << sum << endl;
        }
        if (i > 0) break;
    }
    auto [l, r] = best_pair;
    cout << l << ' ' << r << '\n';
}
