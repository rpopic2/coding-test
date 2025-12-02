#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;

	std::string answer;
	for (int i = 0; i < n; ++i) {
		std::string current;
		std::cin >> current;

		for (int j = 0; j < current.size(); ++j) {
			// std::cout << current.size() << std::endl;
			if (answer.size() <= j) {
				answer.push_back(current[j]);
			} else {
				if (answer[j] != current[j]) {
					answer[j] = '?';
				}
			}
		}
		// std::cout << current;
	}

	std::cout << answer;
}


