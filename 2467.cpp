#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> liquids(N);
    for (int i = 0; i < N; ++i) {
        cin >> liquids[i];
    }
    pair<int, int> current_min;
    int current_min_sum = numeric_limits<int>::max();
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int sum = liquids[i] + liquids[j];
            if (current_min_sum > abs(sum)) {
                current_min_sum = abs(sum);
                current_min = {liquids[i], liquids[j]};
            }
        }
    }
    cout << current_min.first << ' ' <<current_min.second;
}
