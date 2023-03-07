#include <iostream>
#include <array>
#include <algorithm>
#include <cstdlib>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::array<int, 3> arr;

    for (int i = 0; i < 3; ++i) {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());

    for (const auto &i : arr) {
        std::cout << i << ' ';
    }
}
