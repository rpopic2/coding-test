#include <iostream>

int main()
{
    int cnt;
    std::cin >> cnt;
    for (int i; std::cin >> i;)
    {
        if (i == 1)
        {
            --cnt;
            break;
        }
        for (int j = 2; j < i; ++j)
        {
            if (i % j == 0)
            {
                --cnt;
                break;
            }
        }
    }
    std::cout << cnt;
}
