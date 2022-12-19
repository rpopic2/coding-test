#include <iostream>
constexpr int NUM_SIDES = 6;

int main()
{
    int input_n, shell = 1;
    std::cin >> input_n;
    for (int i = 1; i < input_n; ++shell)
    {
        i += shell * NUM_SIDES;
    }
    std::cout << shell;
}
