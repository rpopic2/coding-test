#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

constexpr int COUNT_DICES = 3;
int main()
{
    array<int, COUNT_DICES> a;
    for (int i = 0; i < COUNT_DICES; ++i)
    {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }

    array<int, COUNT_DICES> count_a;

    for (int i = 0; i < COUNT_DICES; ++i)
    {
        int c = count(a.begin(), a.end(), a[i]);
        count_a[i] = c;
    }
    int* m = max_element(count_a.begin(), count_a.end());
    auto f = find(count_a.begin(), count_a.end(), *m);
    cout << *m;
    int caf = f - count_a.begin();
    cout << caf << "\n";
    auto same_eye = m[caf];
    if (*m == 3) 
    {
        cout << 10000 + same_eye * 1000;
    }
    else if (*m == 2)
    {
        cout << 1000 + same_eye * 100;
    }
    else if (*m == 1)
    {
        int *max_eye = max_element(a.begin(), a.end());
        cout << *max_eye * 100;
    }

}

