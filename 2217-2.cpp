#include <iostream>
#include <limits>
#include <vector>

int main() {
    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int n;
    std::cin >> n;

    int ropes[10001]{};
    for (int i = 0; i < n; ++i) {
        int rope;
        std::cin >> rope;
        ropes[rope] += 1;
    }

    int max = 0;
    for (int i = 0; i < 10001; ++i) {
        if (ropes[i] == 0)
            continue;
        if (i * n > max)
            max = i * n;
        n -= ropes[i];
    }
    std::cout << max;
}

