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

	int answer = reals[0];

	for (int i = 1; i < n; ++i) {
		int target = reals[i];

		int a = answer;
		int t = target;
		int counter_a = 2;
		int counter_b = 2;
		while (a != t) {
			if (t > a) {
				a = answer * counter_a;
				counter_a += 1;
			} else if (a > t) {
				t = target * counter_b;
				counter_b += 1;
			}
			// printf("a: %d, t: %d\n", a, t);
		}
		answer = a;
		// std::cout << answer << ',';
	}

	if (answer == reals[n - 1]) {
		answer *= reals[0];
	}

	std::cout << answer;
}



