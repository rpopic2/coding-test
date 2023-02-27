#include <iostream>
#include <algorithm>

constexpr int SET_DISCOUNT = 50;
int main() {
    int high_burger;
    int mid_burger;
    int low_burger;

    int coke;
    int cider;

    std::cin >> high_burger >> mid_burger >> low_burger;
    std::cin >> coke >> cider;

    int cheapest_burger = std::min(
            high_burger, std::min(mid_burger, low_burger));
    int cheapest_drink = std::min(coke, cider);

    std::cout << cheapest_burger + cheapest_drink + SET_DISCOUNT << '\n';
}
