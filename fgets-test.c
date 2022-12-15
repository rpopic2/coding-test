#include <stdio.h>
int main(void)
{
    char buf[3];
//    fgets(buf, 1, stdin);//does nothing since fgets will read 0 chars
//    printf("%s", buf); 
    fgets(buf, 3, stdin);

    // behaviour of c-string
    if (buf[2] == '\0') printf("null\n"); //always print null. type in hi will print null, type in hello will also print null.
    else printf("%c\n", buf[2]);

    if (buf[1] == '\0') printf("null\n"); //always print null. type in hi will print null, type in hello will also print null.
    else printf("%c\n", buf[1]);
}
