#include <iostream>

struct point {
    int x, y;
};

std::istream &operator>>(std::istream &is, point &p) {
    is >> p.x >> p.y;
    return is;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    point p1, p2, p3;
    std::cin >> p1 >> p2 >> p3;

    point vector_p2p3{p3.x - p2.x, p3.y - p2.y};
    point vector_p2p1{p1.x - p2.x, p1.y - p2.y};

    auto det = (vector_p2p3.x * vector_p2p1.y - vector_p2p1.x * vector_p2p3.y) <=> 0;
    int result;
    if (det == 0) {
        result = 0;
    } else if (det > 0) {
        result = 1;
    } else {
        result = -1;
    }
    std::cout << result << '\n';
}

