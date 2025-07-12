#include <iostream>

struct vec {
    long long x, y;

    vec operator -(const vec &rhs) {
        return {x - rhs.x, y - rhs.y};
    }
};

std::istream &operator>>(std::istream &is, vec &p) {
    is >> p.x >> p.y;
    return is;
}

long long det(vec a, vec b) {
    return a.x * b.y - b.x * a.y;
}

int sign(long long l) {
    if (l > 0) {
        return 1;
    } else if (l < 0) {
        return -1;
    }
    return 0;
}

int main() {
    vec p1, p2;
    vec p3, p4;
    std::cin >> p1 >> p2 >> p3 >> p4;

    bool intersects = (sign(det(p2 - p1, p3 - p1)) != sign(det(p2 - p1, p4 - p1)))
            && (sign(det(p3 - p4, p1 - p4)) != sign(det(p3 - p4, p2 - p4)));
    std::printf("%d\n", intersects);
}

