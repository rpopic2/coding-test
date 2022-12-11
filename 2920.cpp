#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string result;
    int cur, prev;
    cin >> prev >> cur;
    if (prev + 1 == cur) result = "ascending";
    else if (prev - 1 == cur) result = "descending";
    prev = cur;
    for (;cin >> cur; prev = cur)
    {
        if (abs(cur - prev) != 1)
        {
            result = "mixed";
            break;
        }
    }
    cout << result;
}
