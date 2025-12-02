#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

using u64 = uint64_t;


int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
    // C++17 이상이면: return std::gcd(a, b);
}

auto main() -> int {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		std::cin >> n;

		std::vector<int> vec(n);
		for (int j = 0; j < n; ++j) {
			std::cin >> vec[j];
		}

		u64 acc = 0;
		for (int i = 0; i < vec.size() - 1; ++i) {
			for (int j = i + 1; j < vec.size(); ++j) {
				acc += gcd(vec[i], vec[j]);
			}
		}
		std::cout << acc << '\n';
	}
}

