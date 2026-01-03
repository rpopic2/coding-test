#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n, b;
	std::cin >> n >> b;
	const std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int target = n;
	std::string result;
	while (true) {
		auto d = digits[target % b];
		result.push_back(d);
		target /= b;
		if (target <= 0)
			break;
	}
	std::reverse(result.begin(), result.end());
	std::cout << result;
}

