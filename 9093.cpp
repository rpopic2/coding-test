#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	std::cin >> t;
	std::string dummy;
	std::getline(std::cin, dummy);

	for (int i = 0; i < t; ++i) {
		std::string s;
		std::getline(std::cin, s);

		std::stringstream ss(s);

		std::string word;
		while (ss >> word) {

			std::reverse(word.begin(), word.end());
			std::cout << word << ' ';
		}
		std::cout << '\n';
	}
}

