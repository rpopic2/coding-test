#include <iostream>
#include <cmath>
using u64 = unsigned long long;

int main() {
    u64 a, b, c;
    std::cout << pow(30000, 2);
    while (std::cin >> a >> b >> c) {
        if (a == 0) break;
        if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
            std::cout << "right\n";
        }
        else std::cout << "wrong\n";
    }
}
