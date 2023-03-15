#include <iostream>

int main() {
    int star_count;
    std::cin >> star_count;

    std::string buf;
    for (int i = 0; i < star_count; ++i) {
        buf += '*';
        std::cout << buf << '\n';
    }

    for (int i = 0; i < star_count - 1; ++i) {
        buf.pop_back();
        std::cout << buf << '\n';
    }
}
