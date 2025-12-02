#include <iostream>

int main() {
	int x;
	std::cin >> x;

	int high = 1;

	int acc = 0;
	int step = 1;
	while (acc + step <= x) {
		acc += step;
		step += 1;
	}

	std::cout << acc;
}

