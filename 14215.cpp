#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>

int main() {
	std::vector<int> edges(3);
	for (int i = 0; i < 3; ++i) {
		std::cin >> edges[i];
	}

	std::sort(edges.begin(), edges.end());
	
	auto shorts = edges[0] + edges[1] - edges[2];
	auto sum = std::accumulate(edges.begin(), edges.end(), 0);
	if (shorts > 0) {
		std::cout << sum;
	} else {
		std::cout << sum + shorts - 1;
	}
}


