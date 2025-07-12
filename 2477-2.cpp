#include <iostream>

int main() {
    int k;
    std::cin >> k;

    constexpr int EDGES_COUNT = 6;

    int acc_vertical = 0;
    int acc_horizontal = 0;
    for (int i = 0; i < EDGES_COUNT; ++i) {
        int orientation;
        int length;

        std::cin >> orientation >> length;

        if (orientation == 1 || orientation == 2) {
            acc_vertical += length;
        }
        if (orientation == 3 || orientation == 4) {
            acc_horizontal += length;
        }
    }

    int area = 
}
