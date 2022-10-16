#include <iostream>
#include <cmath>
using namespace std;

int readPow();

int main()
{
    int a, result = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> a;
        result += a * a;
    }
    cout << result % 10;
    return 0;
}