#include <iostream> 
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int h, w ,n;
        cin >> h >> w >> n;
        int floor = n % h;
        if (floor == 0) floor = h;
        cout << floor;
        int room = (n - 1) / h + 1;
        if (room < 10) cout << 0;
        cout << room << '\n';
    }
}

//h = 3, w = 3
//1st customer : 101
//2nd : 201 ...
//3 -> 301
//4 -> 102
//5 -> 202
//6 -> 302
//7 -> 103
//8-> 203
//9-> 303
//
// >> for xnd cust, gets n % h th floor, ((n - 1) / w) + 1 th room
