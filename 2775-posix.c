#include <unistd.h>
#include <stdio.h>
#define MAX_SIZE 14

/* boilerplates */
#define IBUF_SIZ 65536
char ibuf[IBUF_SIZ], *p = ibuf;
/* read int */
int readint()
{
    p = ibuf;
    read(0, ibuf, IBUF_SIZ);
    int result = *p++ - '0';
    while (1)
    {
        int j = *p;
        if (j == '\n' || j == ' ' || j == '\0') break;
        result *= 10;
        result += j - '0';
        ++p;
    }
    return result;
}
#define BUF_SIZE 65536
char obuf[BUF_SIZE], *q = obuf;
char * const buf_end = obuf + BUF_SIZE;
void buf_flush()
{
    write(1, obuf, q - obuf);
    q = obuf;
}
void bufw(int num)
{
    int digits = 1;
    for (int j = num; j >= 10; j /= 10) ++digits;
    if (q + digits > buf_end) buf_flush();
    for (int j = digits; j--; num /= 10) q[j] = num % 10 + '0';
    q += digits;
    *q++ = '\n';
}
int main(void)
{
    int dp[MAX_SIZE + 1][MAX_SIZE];
    for (int j = 0; j < MAX_SIZE; ++j)
    {
        dp[0][j] = j + 1;
    }
    for (int i = 1; i < MAX_SIZE + 1; ++i)
    {
        dp[i][0] = 1;
        for (int j = 1; j < MAX_SIZE; ++j)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    int T = readint();
    //int T;
    //scanf("%d", &T);
    while (T--)
    {
        int J = readint();
        int K = readint(); // >> K starts from 1!! <<
        //int J, K; // >> K starts from 1!! <<
        //scanf("%d", &J);
        //scanf("%d", &K);
        bufw(dp[J][--K]);
        //printf("%d", dp[J][--K]);
        
    }
    buf_flush();
}
