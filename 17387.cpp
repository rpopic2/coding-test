#include <iostream>

struct point {
    long long x, y;

    bool operator<=(const point &rhs) {
        if (x == rhs.x)
            return y <= rhs.y;
        return x <= rhs.x;
    }
};

struct line {
    point a, b;
};

long long ccw(const line &line, const point &c) {
    point vector_ac {c.x - line.a.x, c.y - line.a.y};
    point vector_ab {line.b.x - line.a.x, line.b.y - line.a.y};

    auto dot_product_k = vector_ac.x * vector_ab.y - vector_ab.x * vector_ac.y;

    // point vector_ca {a.x - c.x, a.y - c.y};
    // point vector_cb {b.x - c.x, b.y - c.y};
    //
    // auto dot_product_k = vector_ca.x * vector_cb.y - vector_cb.x * vector_ca.y;
    if (dot_product_k > 0) {
        return 1;
    } else if (dot_product_k < 0) {
        return -1;
    } else {
        return 0;
    }
    // return dot_product_k;
}

int main() {
    point a, b;
    std::cin >> a.x >> a.y >> b.x >> b.y;

    point c, d;
    std::cin >> c.x >> c.y >> d.x >> d.y;

    auto abc = ccw({a, b}, c);
    auto abd = ccw({a, b}, d);
    auto ab_intersects = abc * abd;

    auto cda = ccw({c, d}, a);
    auto cdb = ccw({c, d}, b);
    auto cd_intersects = cda * cdb;

    // auto cab = ccw(c, a, b);
    // auto dab = ccw(d, a, b);
    // auto ab_intercects = cab * dab;
    //
    // auto acd = ccw(a, c, d);
    // auto bcd = ccw(b, c, d);
    // auto cd_intercects = acd * bcd;

    constexpr std::string_view NO_INTERCECTION = "0\n";;
    constexpr std::string_view INTERCECTS = "1\n";;

    if (ab_intersects > 0 || cd_intersects > 0) {
        std::cout << NO_INTERCECTION;
        return 0;
    } else if (ab_intersects < 0 && cd_intersects < 0) {
        std::cout << INTERCECTS;
        return 0;
    }
    // when collinear

    if(b <= a) std::swap(a, b);
    if(d <= c) std::swap(c, d);

    if(a <= d && c <= b) {
        std::cout << INTERCECTS;
        return 0;
    }
    // if (c <= b && a <= d) {
    //     std::cout << INTERCECTS;
    //     return 0;
    // }
    std::cout << NO_INTERCECTION;
    return 0;

    // printf("%d", abc * abd * cda * cdb == 0);
}


