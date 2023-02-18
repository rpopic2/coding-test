#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#include <limits>
using namespace std;

constexpr int TARGET = 0;

int main() {
    int N;
    cin >> N;
    
    vector<int> liquids(N);
    for (int i = 0; i < N; ++i) {
        cin >> liquids[i];
    }

    int pleft = 0;
    int pright = N - 1;
 
    int current_best = numeric_limits<int>::max();
    pair<int, int> best_pair;

    while (pleft < pright) {
        int c = liquids[pleft] + liquids[pright];
        c = ::abs(c);
        if (c < current_best) {
            current_best = c;
            best_pair = {liquids[pleft], liquids[pright]};
            //cout << pleft << ' ' << pright << endl;
        }

        if (c > TARGET) {
            --pright;
        } else if (c < TARGET) {
            ++pleft;
        } else {
            break;
        }
    }
    auto [l, r] = best_pair;
    cout << l << ' ' << r << '\n';
}
