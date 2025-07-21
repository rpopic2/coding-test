#include <iostream>
#include <cstdint>
#include <vector>

using i64 = std::int64_t;

int main() {
        int n;
        std::cin >> n;

        int tallests_visibles = 0;

        std::vector<i64> buildings(n);
        for (int i = 0; i < n; ++i) {
                auto &h = buildings[i];
                std::cin >> h;
        }

        for (int i = 0; i < n; ++i) {
                const auto b = buildings[i];
                int visibles = 0;
                i64 last_tallest = 0;
                for (int j = i + 1; j < n; ++j) {
                        const auto c = buildings[j];
                        if (c <= last_tallest) {
                                continue;
                        }
                        last_tallest = c;
                        visibles += 1;
                }
                last_tallest = 0;
                for (int j = i - 1; j >= 0; --j) {
                        const auto c = buildings[j];
                        if (c <= last_tallest) {
                                continue;
                        }
                        last_tallest = c;
                        visibles += 1;
                }
                if (visibles > tallests_visibles) {
                        tallests_visibles = visibles;
                }
        }

        std::cout << tallests_visibles << '\n';
}
