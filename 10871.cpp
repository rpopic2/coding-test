#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >> x >> x;
    string buf;
    for (int a; cin >> a;)
    {
        if (a < x) buf += to_string(a) + ' ';
    }
    cout << buf;
}
