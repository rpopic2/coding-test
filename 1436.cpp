#include <iostream>
#include <algorithm>

bool is_number_of_doom(int n) {
    while (n) {
        if (n % 10 == 6) {
            if (n % 1000 == 666)
                return true;
        }
        n /= 10;
    }
    return false;
}

int main() {
    int n;
    std::cin >> n;

    int num = 666;
    while (n--) {
        while (!is_number_of_doom(num++)) { }
    }
    std::cout << --num << '\n';
}
