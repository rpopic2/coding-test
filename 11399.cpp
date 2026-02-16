#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> p[i];
	}
	std::sort(p.begin(), p.end());

	int acc = 0;
	for (int i = 0; i < n; ++i) {
		acc = std::accumulate(p.begin(), std::next(p.begin(), i + 1), acc);
	}
	std::cout << acc;
}

