#include <iostream>
#include <vector>

int main() {
    std::vector<int> primes;

    for (int i = 2; i < 123'456 * 2; ++i) {
        bool is_prime = true;
        for (const auto p : primes) {
            if (i % p == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(i);
        }
    }

    int n;
    while (std::cin >> n) {
        if (n == 0)
            break;

        int primes_count = 0;

        for (const auto p : primes) {
            if (p > n * 2)
                break;
            if (p > n) {
                primes_count += 1;
            }
        }

        std::cout << primes_count << '\n';
    }
}

