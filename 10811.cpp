#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> baskets(n + 1);

    for (int i = 1; i <= n; ++i) {
        baskets[i] = i;
    }


    int a, b;
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b;

        auto b_begin = baskets.begin();
        std::reverse(b_begin + a, b_begin + b + 1);
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << baskets[i] << ' ';
    }
}

