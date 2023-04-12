#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec(9, 0);
    for (int i = 0; i < 9; ++i) {
        std::cin >> vec[i];
    }

    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        sum += vec[i];
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (i == j)
                continue;
            int vsum = sum - vec[i] - vec[j];
            if (vsum == 100) {
                for (int k = 0; k < 9; ++k) {
                    if (k == i || k == j)
                        continue;
                    std::cout << vec[k] << '\n';
                }
                return 0;
            }
        }
    }
}
