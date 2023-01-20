#include <stdio.h>
#include <stdlib.h>
typedef size_t usize;
int main(void) {
    usize size = sizeof(int);
    int *p = malloc(sizeof(int));
    *p = 10;
    printf("%d at %p sizeof %lu", *p, p, size);
    free(p);
}
