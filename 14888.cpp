#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> as(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> as[i];
    }

    int add, sub, mul, div;
    std::cin >> add >> sub >> mul >> div;
}

