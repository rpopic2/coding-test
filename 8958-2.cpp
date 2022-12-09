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
    char *p = &s[0];
    int result;
    for (int i = 0; i < s.length(); ++p)
    {
        cout << *p;
    }
    cout << endl;
    *buf += to_string(result);
}
