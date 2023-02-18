#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

int main() {
    // read input
    int N;
    cin >> N;

    // liquids are given sorted
    vector<int> liquids(N);
    for (int i = 0; i < N; ++i) {
        cin >> liquids[i];
    }

    // setup
    int best_sum = numeric_limits<int>::max();
    pair<int, int> best_pair;
    auto start = liquids.begin();

    // for each negative liquids (it loops at least once, so it can handle positive-only inputs)
    for (const auto &liq : liquids) {

        // perform a binary search for indicies on the left of the current liquid (the input is given sorted)
        auto sim = upper_bound(++start, liquids.end(), liq * -1);

        // lambda fn for updating best pair and sum.
        auto update = [&]() {
            //check for validity
            if (sim == liquids.end()) return;

            int sum = *sim + liq;
            sum = ::abs(sum);

            if (sum < best_sum) {
                best_sum = sum;
                best_pair = {liq, *sim};
            }
        };

        // this update() will be called twice, checking at the upper_bound and after it.
        // first update on the upper_bound
        update();

        // this safe guard ensure that update() will not compare itself
        if (sim == start) continue;
        // second update on before the upper_bound
        --sim;
        update();

        // we don't need to compare positive liquids
        if (liq > 0) break;
    }

    // print out the best pair
    auto [l, r] = best_pair;
    cout << l << ' ' << r << '\n';
}
