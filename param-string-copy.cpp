#include <iostream>

using namespace std;
void change_str(string s);
int main()
{
    string s = "Hello world";
    change_str(s);
    cout << s;
}

void change_str(string s)
{
    s = "Bye world";
}
