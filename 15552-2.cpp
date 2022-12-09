#include <cstdio>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    string buf;
    int a, b;

    cin.ignore(7, '\n');
    char rbuff[8096 * 32];
    cin.getline(rbuff,8096 * 32, EOF);

    istringstream iss(rbuff);
    while (iss >> a >> b)
    {
        buf += to_string(a + b) + "\n";
    }
    cout << rbuff;
    cout << buf;
}
