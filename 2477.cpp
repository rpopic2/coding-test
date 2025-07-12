#include <iostream>
#include <vector>

enum class orientation {
    none, east, west, south, north
};

struct edge {
    orientation orient;
    int length;
};

int main() {
    int k;
    std::cin >> k;

    constexpr int FIELDS_COUNT = 6;
    std::vector<edge> edges(FIELDS_COUNT);

    edge longest_horizontal{}, longest_vertical{};
    int longest_horizontal_index{};
    int longest_vertical_index{};

    for (int i = 0; i < FIELDS_COUNT; ++i) {
        int o;
        edge &e = edges[i];
        std::cin >> o >> e.length;
        e.orient = static_cast<orientation>(o);

        if (e.orient == orientation::east || e.orient == orientation::west) {
            printf("orient hori");
            if (e.length > longest_horizontal.length) {
                longest_horizontal = e;
                longest_horizontal_index = i;
            }
        } else if (e.orient == orientation::south || e.orient == orientation::north) {
            printf("orient vert");
            if (e.length > longest_vertical.length) {
                longest_vertical = e;
                longest_vertical_index = i;
            }
        }
    }

    long long big_surface = longest_horizontal.length * longest_vertical.length;
    int small_horizontal = edges[(longest_horizontal_index + 2) % FIELDS_COUNT].length;
    int small_vertical = edges[(longest_vertical_index - 2) % FIELDS_COUNT].length;
    std::printf("%d, %d)", small_horizontal, small_vertical);
    int small_surface = small_horizontal * small_vertical;

    int surface = big_surface - small_surface;
    long long mellons = surface * k;
    std::cout << mellons << '\n';
}

// 160 * 50 = 100 * 50 + 60 * 50 = 3000 + 5000 = 8000
// - 1200
// = 6800

// ____
// |_  |
//   |_|
// _
// ||_
// |__|
//
//  ___
// | __|
// |_|
//
//    _
//  _| |
// |___|
//

