#include <iostream>
int main()
{
    constexpr size_t C = 10;
    int arr[C] = {1};
    //first element init to 1, others to the default 
    for (const auto& i : arr)
    {
        std::cout << i;
    }
    int* parr = arr;
    for (size_t i = 0; i < C; i++)
    {
        std::cout << *parr + i;
    }
    std::cout << std::endl << arr[-1];
}
