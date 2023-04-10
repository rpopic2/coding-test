#include <iostream>
#include <algorithm>

int main()
{
    bool not_found = true;
    std::string buf(' ', 10);
    for (int i = 0; i < 5; ++i) {
        std::cin >> buf;
        auto found = buf.find("FBI");
        if (found != std::string::npos) {
            std::cout << i + 1 << ' ';
            not_found = false;
        }
    }
    if (not_found)
        std::cout << "HE GOT AWAY!\n";
}
