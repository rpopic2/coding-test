#include <iostream>
#include <cstring>
#include <string>
using namespace std;
constexpr int LEN = 80;

int add_up(int i);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r = 0;


    char dummy[LEN];
    while (cin.getline(dummy, LEN, 'O'))
    {
        char buf[LEN];
        cin.getline(buf, LEN, 'X');
        auto i = strlen(buf) + 1;
        r += add_up(i);
    }
    cout << r - 1;
}

int add_up(int i)
{
    return i * (1 + i) / 2;
}
