#include <iostream>
#include <array>
using namespace std;
constexpr int N = 9;

int main()
{
    int max = 0, max_index = 0;
    for (int i = 0, tmp; i < N; i++)
    {
        cin >> tmp;
        if (tmp <= max) continue;
        max = tmp;
        max_index = i + 1;
    }
    cout << max << '\n' << max_index;
}
