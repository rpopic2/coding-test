#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int prev;
    cin >> prev;
    string result = prev == 1 ? "ascending" : "descending";
    
    for (int cur; cin >> cur; prev = cur)
    {
        if (abs(cur - prev) == 1) continue;
        else result = "mixed"; break;
    }

    cout << result;
}
