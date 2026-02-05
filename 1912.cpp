#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    int acc = 0;
    int minus_best = std::numeric_limits<int>::min();
    int best = 0;//std::numeric_limits<int>::min();
    bool only_minus = true;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        acc += x;
        if (x < 0) {
            minus_best = std::max(minus_best, x);
        } else {
            only_minus = false;
        }
        if (acc < 0) {
            acc = 0;
        }
        best = std::max(best, acc);
    }
    if (only_minus) {
        std::cout << minus_best << '\n';
    } else {
        std::cout << best << '\n';
    }
}

