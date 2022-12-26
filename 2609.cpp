#include <algorithm>
#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    if (b < a) std::swap(a, b);
    int gcd = 0, lcm = 0;
    for (int i = a; i >= 0; --i)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
            break;
        }
    }
    int a_mul = a, b_mul = b;
    while(true)
    {
        if (a_mul == b_mul)
        {
            lcm = a_mul;
            break;
        }
        while (a_mul < b_mul)
        {
            a_mul += a;
        }
        std::swap(a_mul, b_mul);
        std::swap(a, b);
    }

    std::cout << gcd << std::endl;
    std::cout << lcm;
}
