#include <stdio.h>

int main(void)
{
    char hi[1000000];
    scanf("%[^\n]s", hi);
    printf("%s", hi);
}
