#include <iostream>

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	while (true) {
		int a, b;
		std::cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		std::string out;
		if (b % a == 0)
			out = "factor";
		else if (a % b == 0)
			out = "multiple";
		else
			out = "neither";
		std::cout << out << '\n';
	}
}

