
#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    int counter = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            ++counter;
        }
        if (counter == k) {
            std::cout << i;
            return 0;
        }
    }
    std::cout << '0';
}
