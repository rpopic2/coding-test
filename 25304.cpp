#include <iostream>
#include <vector>

int main() {
	int x;
	std::cin >> x;

	int n;
	std::cin >> n;

	int acc = 0;
	for (int i = 0; i < n; ++i) {
		int a, b;
		std::cin >> a >> b;

		acc += a * b;
	}

	auto result = x == acc ? "Yes" : "No";
	std::cout << result;
}


