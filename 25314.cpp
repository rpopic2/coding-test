#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int loop = n / 4;
    for (int i = 0; i < loop; ++i) {
        std::cout << "long ";
    }
    std::cout << "int\n";
}
