#include <iostream>

int main() {
    std::string pile;
    std::cin >> pile;

    int height = 0;
    char last = ' ';
    for (const char c : pile) {
        if (c != last) {
            height += 10;
        }
        else {
            height += 5;
        }
        last = c;
    }

    std::cout << height;
}
