#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string buf;
    int a, b;
    cin >> a;
    while (cin >> a >> b)
    {
        buf += to_string(a + b) + "\n";
    }
    cout << buf;
}
