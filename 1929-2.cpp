#include <iostream>
#include <array>
#include <string>
#include <unistd.h>
using namespace std;
constexpr int NOT_PRIME = 1;
constexpr int MAX_VAL = 1'000'000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    string buf;

    bool nums[MAX_VAL + 1];
    
    nums[1] = NOT_PRIME;
    for (int i = 3; i <= n; ++i)
    {
        if (nums[i] == NOT_PRIME) continue;
        for (int j = 2; i * j <= n; ++j)
        {
            nums[i * j] = NOT_PRIME;
        }
    }
    if (m <= 2) buf = "2\n";
    for (int i = m; i <= n; ++i)
    {
        if (i % 2 == 0) continue;
        if (nums[i] == NOT_PRIME) continue;
        buf += to_string(i) + '\n';
    }
    write(1, buf.c_str(), buf.length());
}


