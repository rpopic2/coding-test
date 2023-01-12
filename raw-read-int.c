#include <unistd.h>
#include <stdio.h>
/* boilerplates */
#define IBUF_SIZ 4
char ibuf[IBUF_SIZ], *p = ibuf;
/* read int */
int readint()
{
    read(0, &ibuf, IBUF_SIZ);
    
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

int main(void)
{
    int result = readint();
    printf("%d\n", result);
    result = readint();
    printf("%d\n", result);
}
