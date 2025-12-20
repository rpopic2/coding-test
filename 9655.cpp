#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    if (n % 2 == 0) {
        std::cout << "CY";
    } else {
        std::cout << "SK";
    }
}

