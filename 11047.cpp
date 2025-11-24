#include <iostream>
#include <vector>

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	std::cin >> n >> k;

	std::vector<int> coins(n);

	for (int i = 0; i < n; ++i) {
		std::cin >> coins[i];
	}

	int counter = 0;
	for (int i = n - 1; i >= 0; --i) {
		int c = coins[i];
		while (k - c >= 0) {
			++counter;
			k -= c;
			//std::cout << c << std::endl;
		}
	}

	std::cout << counter;
}

