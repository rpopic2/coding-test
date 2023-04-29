#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int num_seats;
    int num_vips;

    std::cin >> num_seats >> num_vips;

    std::vector<int> vip_seats;
    vip_seats.reserve(num_vips);

    for (int i = 0; i < num_vips; ++i) {
        int cache;
        std::cin >> cache;
        vip_seats[i] = cache;
    }

}
