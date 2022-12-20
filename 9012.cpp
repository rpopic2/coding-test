#include <iostream>
using namespace std;
constexpr int BIG_NUM = 1 << 16;

void cnt_parens(string &buf)
{
    int parens_to_resolve = 0;
    char c;
    while (cin.get(c) && c != '\n')
    {
        if (c == '(') ++parens_to_resolve;
        else --parens_to_resolve;
        if (parens_to_resolve < 0) break;
    }
    buf += parens_to_resolve == 0 ? "YES\n" : "NO\n";
    if (c != '\n') cin.ignore(BIG_NUM, '\n');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string buf = "";
    cin.ignore(1 << 16, '\n');
    while (cin.peek() != EOF) cnt_parens(buf);
    cout << buf;
}

