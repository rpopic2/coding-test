#include <iostream>

using namespace std;
int main()
{
    auto buf = cin.rdbuf();
    cout << buf;
}
