#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string str;
    getline(cin, str);

    for (char &c : str)
    {
        c = isupper(c) ? tolower(c) : toupper(c);
    }

    cout << str;
    return 0;
}