#include <ios>
#include <iostream>

void test(int &hi);

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int i = 0;
    test(i);
    int &j = i;
    std::cout << j;
}

void test(int &hi)
{
    std::cout << hi;
    ++hi;
}
