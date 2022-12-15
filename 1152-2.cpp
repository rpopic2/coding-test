#include <iostream>
using namespace std;

constexpr auto STR_MAX = 0x7fffffffffffffff;
constexpr auto S_MAX = 1'000'000;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char s[S_MAX], *p = s;
    int result = 1;
    cin.getline(s, STR_MAX);
    for (;*p != '\0';)
    {
        if (*++p != ' ') continue;
        else ++result;
    }
    if (*--p == ' ') --result;
    cout << result;
}
