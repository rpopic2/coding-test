#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;
    int i;
    std::cin >> i;
    if(i >= v.size()) return 0;
    std::cout << v[0];
}
