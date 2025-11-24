#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

struct point {
    int x, y;
};

std::istream &operator>>(std::istream &is, point &p) {
    is >> p.x >> p.y;
    return is;
}

int main() {
    constexpr int COLOR_PAPER_AREA = 10;

    int n;
    std::cin >> n;

    using matrix = std::vector<std::vector<int>>;
    matrix canvas(100, std::vector<int>(100));

    for (int i = 0; i < n; ++i) {
        point p;
        std::cin >> p;

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                canvas[p.x + i][p.y + j] = 1;
                // std::printf("%d %d\n", p.x + i, p.y + j);
            }
        }
    }

    int total_area = 0;

    for (const auto &v : canvas) {
        // for (const auto &i : v) {
        total_area = std::accumulate(v.begin(), v.end(), total_area);
    }

    std::cout << total_area << '\n';
}

