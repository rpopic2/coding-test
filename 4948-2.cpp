#include <cstdio>

constexpr auto MAX = 123'456 * 2;
static bool not_primes[MAX];

int main() {
    not_primes[1] = true;

    for (int i = 2; i * i <= MAX; ++i) {
        if (!not_primes[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                not_primes[j] = true;
            }
        }
    }

    int n;
    while (scanf("%d", &n)) {
        if (n == 0)
            break;

        int primes_count = 0;

        for (int i = n + 1; i <= n * 2; ++i) {
            if (!not_primes[i]) {
                primes_count += 1;
            }
        }

        printf("%d\n", primes_count);
    }
}

