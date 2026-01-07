#include <iostream>
#include <vector>
#include <numeric>

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;

	std::vector<int> vec(n+1);
	std::vector<int> sums(n+1);

	for (size_t i = 1; i <= n; ++i) {
		std::cin >> vec[i];
			sums[i] = sums[i - 1] + vec[i];
	}

	for (int x = 0; x < m; ++x) {
		int i, j;
		std::cin >> i >> j;

		int acc = sums[j] - sums[i - 1];
		std::cout << acc << '\n';
	}
}

