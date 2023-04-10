#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;

    std::vector<int> scores;
    scores.reserve(n);

    int tmp;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        scores.push_back(tmp);
    }

    std::sort(scores.begin(), scores.end(), std::greater<int>());
    std::cout << scores[k - 1] << '\n';
}
