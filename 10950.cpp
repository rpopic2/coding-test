#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (;t > 0; --t)
    {
        int a, b;
        cin >> a >> b;
        cout << a + b << '\n';
    }
}
