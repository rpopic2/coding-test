#include <iostream>
char buf[100];
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    while (std::cin.getline(buf, 101)) {
        std::cout << buf << '\n';
    }
}
