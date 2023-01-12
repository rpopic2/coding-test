#include <unistd.h>
#include <stdio.h>
#define BUF_SIZE 4
#define T_SIZE 7

char getch(void)
{
    char *buf;
    read(0, &buf, 1);
    return *buf;
}
int geti(size_t buf_size)
{
    char buf[BUF_SIZE], *p = buf, c;
    read(0, &buf, BUF_SIZE);
    int a;
    int result = *p++ - '0';
    while (1)
    {
        int j = *p;
        if (j == '\n') break;
        else if (j == ' ')
        {
            a = result;
            result = *++p - '0';
        }
        result *= 10;
        result += j - '0';
        ++p;
    }
    return a + result;
}
int main(void)
{
    int t = gett();
    printf("t %d\n", t);
    for (;t--;)
    {
        int sum = geti(BUF_SIZE);
        printf("sum %d\n", sum);
    }
}
