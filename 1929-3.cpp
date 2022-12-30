#include <unistd.h>
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
    std::bitset<1000001> nums;
    
    nums[1] = 1;
    if (n <= 2)
    {
        buf_write(2);
        n = 3;
    }
    for (int i = 3; i <= m; i += 2)
    {
        if (nums[i]) continue;
        for (int j = 3; i * j <= m; ++j)
        {
            nums[i * j] = 1;
        }
        if (i >= n) buf_write(i);
    }
    buf_flush();
}

