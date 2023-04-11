#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;

    // baskets[0] is always 0 and not used
    std::vector<int> baskets;
    baskets.reserve(n + 1);

    for (int i = 0; i <= n; ++i) {
        baskets.push_back(i);
    }

    int buf_a, buf_b;
    for (int i = 0; i < m; ++i) {
        std::cin >> buf_a >> buf_b;
        std::swap(baskets[buf_a], baskets[buf_b]);
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << baskets[i] << ' ';
    }
    std::cout << '\n';
}
