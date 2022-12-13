#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, prod;
    cin >> a >> b >> c;
    prod = a * b * c;
    string buf, prod_str = to_string(prod);
    for (int i = 0; i < 10; i++)
    {
        long c = count(prod_str.begin(), prod_str.end(), '0' + i);
        buf += to_string(c) + '\n';
    }
    cout << buf;
}
