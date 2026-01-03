#include <iostream>
#include <numeric>
#include <cmath>

constexpr int COLUMNS = 6;

struct point {
    int x, y;

};


bool operator==(const point &lhs, const point &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
std::istream &operator>>(std::istream &is, point &p) {
    return is >> p.x >> p.y;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        point p1, p2;
        int r1, r2;
        std::cin >> p1 >> r1 >> p2 >> r2;

        double distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

        if (p1 == p2 && r1 == r2) {
            std::cout << "-1\n";
        } else if (p1 == p2 || distance > r1+r2 || distance < abs(r1-r2)) {
            std::cout << "0\n";
        } else if (distance == r1+r2 || distance == abs(r1-r2)) {
            std::cout << "1\n";
        } else {
            std::cout << "2\n";
        }
    }
}

