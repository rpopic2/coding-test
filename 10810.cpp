#include <iostream>
#include <vector>

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> baskets(n + 1);

	for (int a = 0; a < m; ++a) {
		int i, j, k;
		std::cin >> i >> j >> k;

		for (int b = i; b <= j; ++b) {
			baskets[b] = k;
		}
	}
	
	for (size_t a = 1; a < baskets.size(); ++a) {
		std::cout << baskets[a] << ' ';
	}
}

