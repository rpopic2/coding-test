#include <iostream>

int main() {

    int acc = 0;
    int n;
    while (std::cin >> n) {
        if (n >= 0) {
            acc += n;
        } else {
            int minus_acc = -n;
            while (std::cin.peek() == '+') {
                std::cin >> n;
                minus_acc += n;
            }
            acc -= minus_acc;
        }
        // std::cout << "found " << i << std::endl;
    }
    std::cout << acc;
}

// -1-2-3-4-5
// all plus/minus-> just add
// 55-50+40
// 55-50-80
// 55-50+40-90+100-70

