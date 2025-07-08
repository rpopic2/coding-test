#include <cmath>
#include <iostream>
#include <vector>

struct point {
    double x, y;
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    point start_point;
    std::cin >> start_point.x >> start_point.y;

    point next_point;
    std::cin >> next_point.x >> next_point.y;

    double area = 0;
    for (int i = 1; i < n; ++i) {
        point p;
        std::cin >> p.x >> p.y;

        point a = start_point;
        point b = next_point;
        point c = p;

        double tmp = (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);

        // double tmp = (a.x * b.y - b.x * a.y) + (b.x * c.y - c.x * b.y) + (c.x * a.y - a.x * c.y);
        // double surface = std::abs(tmp * 0.5);    // 여기서 abs를 넣으면 면적이 음수여서 깎여야 하는 부분이 안깎임!!
        area += tmp * 0.5;

        next_point = p;
    }

    std::printf("%.1lf", std::abs(area));
}

//  _
// / \
// \ /
//
//  _
// | |
//  -

