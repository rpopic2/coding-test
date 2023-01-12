#include <stdio.h>
int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b)
    {
        int tmp = a;
        a = b, b = tmp;
    }
    int gcd = 0, lcm = 0;
    for (int i = a; i >= 0; --i)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
            break;
        }
    }
    lcm = a * b / gcd;
    printf("%d\n%d", gcd, lcm);
}
