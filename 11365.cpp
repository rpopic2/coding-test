#include <iostream>
#include <algorithm>

int main() {

    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string buf;

    while (std::getline(std::cin, buf)) {
        if (buf == "END")
            return 0;
        std::reverse(buf.begin(), buf.end());
        std::cout << buf << '\n';
    }
}
