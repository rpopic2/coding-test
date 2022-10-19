#include <iostream>
using namespace std;
int main()
{
    int y, result = 0;
    cin >> y;
    if (y % 4 == 0)
    {
        if (y % 100 != 0 || y % 400 == 0)
            result = 1;
    }
    cout << result;

    return 0;
}