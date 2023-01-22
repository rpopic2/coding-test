#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int m2 = 0;
    int m1 = 1;
    for (int i = 2; i < n; ++i) {
        int current = m1 + m2;
        m2 = m1;
        m1 = current;
    }
    std::cout << m1 + m2;
}
