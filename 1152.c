#include <stdio.h>
#include <unistd.h>
#define S_MAX 1000001

int main(void)
{
    char s[S_MAX], *p = s;
    int wc = 1;
    read(0, s, S_MAX);
    for (;*p != '\0';)
    {
        if (*++p != ' ') continue;
        else ++wc;
    }
    if (*--p == '\n' && *--p == ' ') --wc;
    printf("%i", wc);
}
