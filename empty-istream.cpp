#include <iostream>

int main()
{
    int a, b;
    while (!std::cin.eof())
    {
        std::cin >> a >> b;
        std::cout << a + b;
        std::cout << "not EOF\n";
    }
    std::cout << "EOF!";
}
