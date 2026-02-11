#include <iostream>
#include <vector>

using un = unsigned;
using vec = std::vector<un>;
using mat = std::vector<vec>;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m;
    std::cin >> n >> m;

    mat lines(n, vec(n));
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < n; ++j) {
            vec &target = lines[j];
            un val;
            std::cin >> val;
            target[i] = val;
            if (i > 0)
                target[i] += target[i - 1];
        }
    }

    for (int i = 0; i < m; ++i) {
        un x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        x1 -= 1, y1 -= 1, x2 -= 1, y2 -= 1;

        un acc = 0;
        for (int j = y1; j <= y2; ++j) {
            auto &target = lines[j];
            un dx = x1 > 0 ? target[x1 - 1] : 0;
            acc += target[x2] - dx;
        }
        std::cout << acc << '\n';
    }
}

