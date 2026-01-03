#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    std::cin >> n;

    constexpr int num_sizes = 6;
    std::vector<int> ordered(num_sizes);
    for (int i = 0; i < num_sizes; ++i) {
        std::cin >> ordered[i];
    }

    int t, p;
    std::cin >> t >> p;

    int num_t_bundles = 0;
    for (int i = 0;i < num_sizes; ++i) {
        int size = ordered[i];
        num_t_bundles += size / t;
        if (size % t > 0) {
            num_t_bundles += 1;
        }
    }

    int num_p_bundles = n / p;
    int num_p_ea = n % p;

    std::cout << num_t_bundles << '\n';
    std::cout << num_p_bundles << ' ' << num_p_ea;
}

