#include <iostream>

int main()
{
    std::cin.ignore(1 << 16, '%');
    std::string buf;
    std::cin >> buf;
    std::cout << buf;
}
