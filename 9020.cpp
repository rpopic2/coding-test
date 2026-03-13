#include <iostream>
#include <bitset>

std::bitset<10001> nprimes(1);

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    nprimes[1] = true;
    for (int i = 2; i < 10001; ++i) {
        for (int j = 2; j * i < 10001; ++j) {
            nprimes[i * j] = true;
        }
    }

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        // for (int i = n - 1; i >= n / 2; --i) {
        for (int i = n / 2; i < n; ++i) {
            if (nprimes[i])
                continue;
            if (nprimes[n - i])
                continue;
            std::cout << n - i << ' ' << i << '\n';
            break;
        }
    }
}

