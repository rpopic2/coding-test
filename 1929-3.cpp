#include <bitset>
#include <unistd.h>
using namespace std;
constexpr int NOT_PRIME = 1;
constexpr int MAX_VAL = 1'000'001;
constexpr int BUF_SIZE = 1 << 16;

char buf[BUF_SIZE], *p = buf;
char * const buf_end = buf + BUF_SIZE;
inline void buf_flush()
{
    write(1, buf, p - buf);
    p = buf;
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
    bitset<MAX_VAL> nums;
    
    nums[1] = NOT_PRIME;
    if (n <= 2)
    {
        buf_write(2);
        n = 3;
    }
    for (int i = 3; i <= m; i += 2)
    {
        if (nums[i] == NOT_PRIME) continue;
        for (int j = 2; i * j <= m; ++j)
        {
            nums[i * j] = NOT_PRIME;
        }
        if (i >= n) buf_write(i);
    }
    buf_flush();
}

