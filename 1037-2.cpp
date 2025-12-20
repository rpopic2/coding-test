#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector<int> reals(n);

	for (int i = 0; i < n; ++i) {
		std::cin >> reals[i];
	}
	std::sort(reals.begin(), reals.end());

	std::cout << reals[0] * reals[n - 1];
}

