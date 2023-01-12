#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num_stairs;
    cin >> num_stairs;
    if (num_stairs == 0) {
        cout << 0;
        return 0;
    }
    else if (num_stairs == 1) {
        int c;
        cin >> c; 
        cout << c;
        return 0;
    } else if (num_stairs == 2) {
        int a, b;
        cin >> a >> b;
        cout << a + b;
        return 0;
    }
    vector<int> stairs(num_stairs);
    for (int i = 0; i < num_stairs; ++i) {
        cin >> stairs[i];
    }

    vector<pair<int, int>> cost(num_stairs);
    cost[0] = {stairs[0], stairs[0]};
    cost[1] = {stairs[0] + stairs[1], stairs[0] + stairs[1]};
    for (int i = 2; i < num_stairs; ++i) {
        cost[i].first = stairs[i] + stairs[i - 1] + cost[i - 3].first;
        cost[i].second = stairs[i] + stairs[i - 2] + std::max(cost[i - 3].second, cost[i - 4].second);
    }
    auto last_cost = cost[num_stairs - 1];
    std::cout << std::max(last_cost.first, last_cost.second) << '\n';
}
