#include <iostream>
#include <string>
using namespace std;

inline void write_score(string s, string *buf);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string obuf, ibuf;
    cin >> ibuf;
    while (cin >> ibuf)
    {
        write_score(ibuf, &obuf);
    }
    cout << obuf;
}

inline void write_score(string s, string *buf)
{
    int tmp = 0, r = 0;
    for (auto &c : s)
    {
        if (c == 'O')
        {
            tmp += 1;
            r += tmp;
        }
        else tmp = 0;
    }
    *buf += to_string(r) + '\n';
}
