#include <stdio.h>

int main(void) {
    char buf[1001];
    scanf("%s", buf);
    char *p = buf;
    printf("%s\n", p);
    while (*++p) {
        printf("%s\n", p);
    }
}

