#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    std::vector<int> back_buffer(n);

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            int x;
            std::cin >> x;

            if (j == 0) {
                back_buffer[j] = vec[j] + x;
            } else if (j == i - 1) {
                back_buffer[j] = vec[j - 1] + x;
            } else {
                back_buffer[j] = std::max(vec[j - 1], vec[j]) + x;
            }
            // std::cout << vec[j] << '\n';
        }
        std::swap(vec, back_buffer);
    }

    auto result = std::max_element(vec.begin(), vec.end());
    std::cout << *result << '\n';
}

