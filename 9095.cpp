#include <iostream>
#include <algorithm>

using namespace std;
const size_t MAX = 10;

int a[MAX];

int main()
{
    //int T;
    //cin >> T;
    //int ns[T];
    //for (int i = 0; i < T; i++)
    //{
        //cin >> ns[i];
    //}
    a[0] = 1;
    int n;
    cin >> n;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= 3; i++)
        {
            int j = k - i;
            a[k] += a[j];
        }
    }

    cout << a[n];
    cout << endl;
    return 0;
}
