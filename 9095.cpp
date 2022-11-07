#include <iostream>
#include <algorithm>

using namespace std;
const size_t MAX = 10;

int a[MAX];

int main()
{
    a[0] = 1;
    int n;
    int result = 0;
    cin >> n;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= 3; i++)
        {
            int j = n - i;
            a[k] += a[j];
            result += a[j];
        }
    }

    cout << result;
    cout << endl;
    return 0;
}
