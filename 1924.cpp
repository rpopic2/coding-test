#include <iostream>
#include <vector>
#include <array>

std::array<std::string, 7> weekdays = {
	"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
};


std::array<int, 12> days_in_month = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int main() {
	int x, y;
	std::cin >> x >> y;

	int acc = 0;

	for (int i = 0; i < x - 1; ++i) {
		acc += days_in_month[i];
	}

	acc += y - 1;

	std::cout << weekdays[acc % 7];
}

