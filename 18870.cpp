#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        x[i] = num;
    }
    std::vector<int> x_prime = x;
    std::sort(x_prime.begin(), x_prime.end());
    auto end = std::unique(x_prime.begin(), x_prime.end());

    for (int num : x) {
        auto it = std::lower_bound(x_prime.begin(), end, num);
        std::cout << it - x_prime.begin() << ' ';
    }
}

