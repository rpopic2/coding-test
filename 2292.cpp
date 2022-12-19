#include <iostream>
constexpr int NUM_SIDES = 6;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned long long input_n;
    std::cin >> input_n;

    if (input_n == 1)
    {
        std::cout << 1;
        return 0;
    }
    else if (input_n < 8)
    {
        std::cout << 2;
        return 0;
    }

    unsigned long long i = 8, cur_shell = 2, increment = 12;
    for (; i < input_n; ++cur_shell)
    {
        i += increment;
        increment += NUM_SIDES;
    }
    if (input_n == i) ++cur_shell;
    std::cout << cur_shell;
}

//1차 껍질 : 1
//2차 : 2 ~ 7 | 5
//3차 : 8 ~ 19 | 11
//4차 : 20 ~ 37 | 17
//5차 : 38 ~ 61 | 23
//
//첫 껍질 빼고 6씩 증가

