#include <iostream>
#include <cstdint>
#include <vector>

using i64 = std::int64_t;

struct vec {
    i64 x, y;

    vec operator-(const vec &rhs) {
        return {x - rhs.x, y - rhs.y};
    }
};

i64 det(const vec &a, const vec &b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    int n;
    std::cin >> n;

    int tallests_visibles = 0;

    std::vector<i64> buildings(n);
    for (int i = 0; i < n; ++i) {
        auto &h = buildings[i];
        std::cin >> h;
    }

    for (int i = 0; i < n; ++i) {
        const auto b = buildings[i];
        i64 visibles = 0;
        vec b_pos = {i, b};

        for (int j = i + 1; j < n; ++j) {
            printf("<%d>", j);
            const auto c = buildings[j];
            vec c_pos = {j, c};

            bool is_visible = true;
            for (int k = i + 1; k < j; ++k) {
                const auto d = buildings[k];
                vec d_pos = {k, d};

                vec bc = c_pos - b_pos;
                vec bd = d_pos - b_pos;
                printf("{det:%lld, i:%d j:%d k:%d}", det(bd, bc), i, j, k);
                if (det(bd, bc) <= 0) {
                    is_visible = false;
                    break;
                }
            }
            if (is_visible) {
                visibles += 1;
                // printf("visibld(b:%lld, c:%lld,v:%lld)", b, c, visibles);
            }
        }
        for (int j = i - 1; j >= 0; --j) {
            const auto c = buildings[j];
            vec c_pos = {j, c};

            bool is_visible = true;
            for (int k = j + 1; k < i; ++k) {
                const auto d = buildings[k];
                vec d_pos = {k, d};

                vec bc = c_pos - b_pos;
                vec bd = d_pos - b_pos;
                if (det(bd, bc) <= 0) {
                    is_visible = false;
                    break;
                }
            }
            if (is_visible) {
                visibles += 1;
            }
        }

        if (visibles > tallests_visibles) {
            tallests_visibles = visibles;
        }
    }

    std::cout << tallests_visibles << '\n';
}
