#include <iostream>
#include <vector>
#include <cstdint>

using i64 = int64_t;

int main() {
    i64 A, B;
    std::cin >> A >> B;

    i64 a = A, b = B;

    while (a != b) {
        int multiplier = 1;
        while (a < b) {
            a += A;
        }
        multiplier = 1;
        while (b < a) {
            b += B;
        }
        // printf("%lld,%lld\n", a, b);
    }
    std::cout << a;
}

