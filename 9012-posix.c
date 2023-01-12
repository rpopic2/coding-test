#include <stdio.h>
#include <unistd.h>
#define MAX_LEN 55

char buf[MAX_LEN + 1];

int main(void)
{
    int cnt;
    scanf("%d", &cnt);
    while (cnt--)
    {
        int parens = 0;
        read(0, buf, MAX_LEN);
        for (int i = 0; parens >= 0 && buf[i] != '\n'; ++i)
        {
            parens += buf[i] == '(' ? 1 : -1;
            printf("%d,", parens);
        }
        puts(parens == 0 ? "YES" : "NO");
    }
}

