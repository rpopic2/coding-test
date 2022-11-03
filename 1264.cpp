#include <iostream>
#include <string>

using namespace std;

const string s = "aeiou";
const string t = ",.!?";
const char eof = '#';

int main()
{
    int found;
    string u;
    cin >> u;
    for (int i = 0; i < u.length(); i++)
    {
        int b = 0;
        do
        {
            b = s.find(u[i], b);
        } while (b != -1);
    }
    cout << found;
}