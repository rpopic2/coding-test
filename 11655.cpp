#include <iostream>
#include <vector>

int main() {
	std::string s;
	std::cin >> s;

	for (auto &c : s) {
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
			c += 13;
		}
	}
	std::cout << s;
}

