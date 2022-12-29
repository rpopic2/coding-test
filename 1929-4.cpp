#include <unistd.h>
#include <stdio.h>
#include <bitset>
constexpr int BUF_SIZE = 1 << 15;

char rbuf[BUF_SIZE], *p = rbuf;
char * const buf_end = rbuf + BUF_SIZE;
inline void buf_flush()
{
    write(1, rbuf, p - rbuf);
    p = rbuf;
}
inline void buf_write(int num)
{
    int digits = 1;
    for (int j = num; j >= 10; j /= 10) ++digits;
    if (p + digits > buf_end) buf_flush();
    for (int j = digits; j--; num /= 10) p[j] = num % 10 + '0';
    p += digits;
    *p++ = '\n';
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    std::bitset<500'001> nums;
    
    nums[1] = 1;
    if (n <= 2)
    {
        buf_write(2);
        n = 3;
    }
    for (int i = 3; i <= m; ++i)
    {
        if (nums[i]) continue;
        int j = 2;
        int mul = i * j / 2;
        while(mul <= m)
        {
            nums[mul] = 1;
            ++j;
            mul = i * j / 2;
        }
        if (i >= n) buf_write(i);
    }
    buf_flush();
}

