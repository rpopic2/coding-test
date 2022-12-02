#include <iostream>
#include <string>
using namespace std;

constexpr char STAR = '*';
constexpr char SP = ' ';
int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int spc = N - i;
        cout << std::string(spc, SP);
        cout << std::string(i, STAR);
        cout << '\n';
    }
}
