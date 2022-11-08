#include <iostream>
using namespace std;

int a[10];

int main()
{
    int n;
    cin >> n;
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i-1] * i;
    }
    
    cout << a[n] << "\n";
    return 0;
}

