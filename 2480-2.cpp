#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

constexpr int DICES = 3;

int two_same(int eye);
int main()
{
    array<int, DICES> a;
    for (int i = 0; i < DICES; ++i)
    {
        int temp;
        cin >> temp;
        a[i] = temp;
    }

    int answer;
    if (a[0] == a[1])
    {
        if (a[1] == a[2]) answer = 10000 + a[0] * 1000;
        else answer = two_same(a[0]);
    }
    else if (a[0] == a[2])
    {
        answer = two_same(a[0]);
    }
    else if (a[1] == a[2])
    {
        answer = two_same(a[1]);
    }
    else answer = *max_element(a.begin(), a.end()) * 100;
    cout << answer;
}

int two_same(int eye)
{
    return 1000 + eye * 100;
}
