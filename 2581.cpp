#include <iostream>
#include <bitset>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::bitset<10'000> bs;

    // int min = -1;
    int sum = 0;
    bs[1] = true;
    bs[2] = true;

    for (int i = 1; i <= m; i += 2) {
        if (bs[i])
            continue;
        for (int j = 2; i * j <= m; ++j) {
            bs[i * j] = true;
        }
    }

    int acc = 0;
    int min = -1;
    for (int i = n; i <= m; ++i) {
	if (min == -1)
		min = i;
	acc += i;
    }

    if (min == -1) {
	    std::cout << "-1";
    } else {
	    std::cout << acc << '\n' << min;
    }
}
