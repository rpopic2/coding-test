#include <iostream>
using namespace std;

int main()
{
    int repeat;
    string ibuf, obuf;
    cin >> ibuf;
    while (cin >> repeat >> ibuf)
    {
        for (auto &c : ibuf)
        {
            obuf += string(repeat, c);
        }
        obuf += '\n';
    }
    cout << obuf;
}
