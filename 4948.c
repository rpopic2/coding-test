#include <stdio.h>
#include <stdbool.h>

#define MAX 123456 * 2

int main() {
    bool not_primes[MAX] = {};
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


