#include <iostream>

using namespace std;

const int MAX=10;
int a[MAX];

int main()
{
    a[1] = 1;

    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        a[i] = a[i-1] + a[i-2] + a[i-3];
    }

    cout << a[n];

    return 0;
}
