#include <iostream>
#include <algorithm>

using namespace std;
const size_t MAX = 10;

int a[MAX];

int main()
{
    a[0] = 1;
    int n, r = 0;
    cin >> n;

    for (int k = 0; k < n; k++)
    {
        for (int i = 1; i <= 3; i++)
        {
            int j = n - i;
            if (j < 0) break;
            r += a[j];
        }
    }

    a[n] = r;

    cout << r;
    cout << endl;
    return 0;
}
