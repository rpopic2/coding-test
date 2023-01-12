#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
class intcomp {
public:
    bool operator()(const int &lhs, const int &rhs) const {
        return lhs > rhs;
    }
};
using knapsack = std::map<int, int, intcomp>;

int main() {
    int N, K;
    std::cin >> N >> K;
    knapsack sack;
    for (int a, b, i = 0; i < N; ++i) {
        std::cin >> a >> b;
        if (a > K) continue;
        auto orig = sack[a];
        if (orig != 0 && orig > b) continue;
        sack[a] = b;
    }
    std::map<int, int> results;
    for (const auto &item : sack) {
        auto current_weight = item.first;
        results[current_weight] = item.second;
        for (const auto &other : sack) {
            if (current_weight + other.first > K || current_weight == other.first) continue;
            results[current_weight] = std::max(item.second, item.second + other.second);
            
        }
    }
    for (auto &a:results)std::cout << a.second<<std::endl;
    auto max_results = *std::max_element(results.begin(), results.end(), [](auto a, auto b){return a > b;});
    std::cout << max_results.second;
}
