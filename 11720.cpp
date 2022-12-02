#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string ns;
    cin >> ns;

    int a = 0;
    for (int i = 0; i < N; i++)
    {
        a += ns[N] - '0';
    }
    cout << a;
}
