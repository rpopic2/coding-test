#include <stdio.h>
#include <unistd.h>
int main(void)
{
    char buf[4];
    read(0, buf, 3);

    if (buf[3] == '\0') printf("null\n");
    else printf("%d\n", buf[3]);
    if (buf[2] == '\0') printf("null\n");
    else printf("%c\n", buf[2]);

    if (buf[1] == '\0') printf("null\n");
    else printf("%c\n", buf[1]);
}
