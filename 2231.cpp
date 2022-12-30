#include <stdio.h>
constexpr int MAX_DIFF = 54;
inline int disasm_sum(int n)
{
    int sum = n;
    for (; n > 0; n /= 10)
    {
        sum += n % 10;
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    int constructor = 0;
    for (int i = n - MAX_DIFF; i < n; ++i)
    {
        if (disasm_sum(i) == n)
        {
            constructor = i;
            break;
        }
    }
    printf("%d", constructor);
}

