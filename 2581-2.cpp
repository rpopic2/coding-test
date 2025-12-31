#include <iostream>
#include <vector>

int main() {
	int m, n;
	std::cin >> m >> n;

	std::vector<bool> not_primes(10001);
	not_primes[1] = true;

	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j * i <= n; ++j) {
			not_primes[j * i] = true;
		}
	}

	int acc = 0;
	constexpr int NOT_FOUND = -1;
	int min = NOT_FOUND;
	for (int i = m; i <= n; ++i) {
		if (not_primes[i])
			continue;
		acc += i;
		if (min == NOT_FOUND)
			min = i;
	}

	if (min == NOT_FOUND) {
		std::cout << "-1";
	} else {
		std::cout << acc << '\n' << min;
	}
}

