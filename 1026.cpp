#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> b(n);

	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end(), std::greater<int>());

	int acc = 0;
	for (int i = 0; i < n; ++i) {
		acc += a[i] * b[i];
	}

	std::cout << acc;
}
