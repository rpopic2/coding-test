#include <iostream>
using namespace std;

constexpr long STR_MAX = 0x7fffffffffffffff;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int i = 0;
    string dummy;
    for (cin.ignore(2, ' '); cin.ignore(STR_MAX, ' '); ++i) { }
    cout << i;
}
