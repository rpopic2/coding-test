#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> stairs(N);
    for (int i = 0; i < N; ++i) {
        cin >> stairs[i];
    }
    vector<pair<int, int>> costs(N);
    costs[0] = {stairs[0], stairs[0]};
    costs[1] = {stairs[0] + stairs[1], stairs[1]};
    for (int i = 2; i < N; ++i) {
        costs[i].first = costs[i - 1].second + stairs[i];
        auto two_before = costs[i - 2];
        costs[i].second = std::max(two_before.first, two_before.second) + stairs[i];
    }
    auto last_cost = costs[N - 1];
    std::cout << std::max(last_cost.first, last_cost.second);

}
