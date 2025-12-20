#include <cstring>
#include <iostream>

int main() {
    int *p = new int[1000];
    std::cin >> p[0];

    std::memmove(p, p + 1, 1000);

    std::cout << p[0];
}

