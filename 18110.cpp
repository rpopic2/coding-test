#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << '0';
        return 0;
    }

    float cutout = float(n) * 0.15f;
    cutout = std::roundf(cutout);

    std::vector<float> rates(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> rates[i];
    }
    std::sort(rates.begin(), rates.end());

    float sum = std::accumulate(
            std::next(rates.begin(), cutout),
            std::prev(rates.end(), cutout),
            0);

    float average = sum / (float)(n - cutout - cutout);
    int average_int = std::roundf(average);

    std::cout << average_int;
}

