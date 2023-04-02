#include <iostream>

int main()
{
    using u32 = unsigned int;

    u32 fixed, variable;
    u32 price;
    std::cin >> fixed >> variable >> price;

    if (variable >= price) {
        std::cout << "-1" << "\n";
        return 0;
    }

    u32 share = price - variable;
    auto break_even = fixed / share + 1;

    std::cout << break_even;
}

