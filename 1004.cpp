#include <cmath>
#include <iostream>
#include <vector>

struct point {
    float x, y;
};

struct planetary {
    float x, y, radius;

    bool contains(point p) {
        double distance = std::pow(p.x - x, 2) + std::pow(p.y - y, 2);
        return distance < std::pow(radius, 2);
    }
    // . . x . .
    // . x x x .
    // x x o x x
    // . x x x .
    // . . x . .
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        point start;
        point end;
        std::cin >> start.x >> start.y >> end.x >> end.y;

        int n;
        std::cin >> n;

        int in_outs = 0;
        for (int j = 0; j < n; ++j) {
            planetary p;
            std::cin >> p.x >> p.y >> p.radius;

            if (p.contains(start) != p.contains(end)) {
                in_outs += 1;
            }
        }
        std::cout << in_outs << '\n';
    }
}

