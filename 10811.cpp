#include <iostream>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> baskets;
    baskets.reserve(n);

    for (int i = 0; i < n; ++i) {
        baskets[i] = i + 1;
    }


    int a, b;
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b;
        ++a, ++b;
        auto b_begin = baskets.begin();
        std::reverse(b_begin + a, b_begin + b);
    }

    std::cout << baskets[0];
    for (auto i : baskets) {
        std::cout << i << '.';
    }
}

