#include <iostream>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int x_cost_per_litre;
    std::cin >> x_cost_per_litre;

    int y_base;
    std::cin >> y_base;

    int y_thresh;
    std::cin >> y_thresh;

    int y_cost_per_litre;
    std::cin >> y_cost_per_litre;

    int usage;
    std::cin >> usage;

    int x_total = x_cost_per_litre * usage;

    int y_total = y_base;
    if (usage > y_thresh) {
        int over = usage - y_thresh;
        y_total += over * y_cost_per_litre;
    }

    std::cout << std::min(x_total, y_total) << '\n';
}
