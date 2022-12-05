#include <iostream>
using namespace std;

int main()
{
    unsigned int sum;
    while(true)
    {
        unsigned int a, b;
        cin >> a >> b;
        sum = a + b;
        if (sum == 0) break;
        cout << sum << '\n';
    }
}
