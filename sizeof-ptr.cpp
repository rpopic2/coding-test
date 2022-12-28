#include <iostream>
int main()
{
    std::cout << sizeof(char *);
    std::cout << sizeof(void *);
    std::cout << sizeof(int *);
    int i = 1;
    int *p = &i;
    int **pp = &p;
    int j = **pp;
    std::cout << j;
}
