#include <iostream>

struct vec {
    long long x, y;

    vec operator-(const vec &rhs) {
        return {x - rhs.x, y - rhs.y};
    }

    bool operator<=(const vec &rhs) {
        if (x == rhs.x) {
            return y <= rhs.y;
        }
        return x <= rhs.x;
    }
};

std::istream &operator>>(std::istream &is, vec &v) {
    is >> v.x >> v.y;
    return is;
}

long long det(const vec &a, const vec &b) {
    return a.x * b.y - b.x * a.y;
}

int sign(long long l) {
    if (l > 0) {
        return 1;
    } else if (l < 0) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    vec a, b;
    vec c, d;
    std::cin >> a >> b >> c >> d;

    vec ab = b - a;
    vec ac = c - a;
    vec ad = d - a;

    auto abc = sign(det(ab, ac));
    auto abd = sign(det(ab, ad));

    vec cd = d - c;
    vec ca = a - c;
    vec cb = b - c;

    auto cda = sign(det(cd, ca));
    auto cdb = sign(det(cd, cb));

    bool intersects = false;
    bool is_collinear = abc == 0 && abd == 0 && cda == 0 && cdb == 0;
    if (is_collinear) {
        if (b <= a)
            std::swap(a, b);
        if (d <= c)
            std::swap(c, d);

        intersects = a <= d && c <= b;
    } else {
        intersects = abc != abd && cda != cdb;
    }

    std::printf("%d\n", intersects);
}


