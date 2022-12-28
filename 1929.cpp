#include <iostream>
#include <array>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;

    array<int, 1'000'000> primes;
    int *insp = primes.begin();
    *insp++ = 2;
    string buf;
    for (int i = 2; i <= n; ++i)
    {
        if (i % 2 == 0) continue;
        bool is_prime = true;
        for (auto &pr : primes)
        {
            if (pr == 0) break;
            if (i % pr == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
        {
            *insp++ = i;
            if (i < m) continue;
            buf += to_string(i) + '\n';
        }
    }
    cout << buf;
}

