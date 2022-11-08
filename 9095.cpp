#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const size_t MAX = 10;


int main()
{
    int T;
    cin >> T;

    vector<int> ns;
    for (int i = 0; i < T; i++)
    {
        int tmp;
        cin >> tmp;
        ns.push_back(tmp);
    }
    int max = *max_element(ns.begin(), ns.end());

    int a[MAX];
    a[0] = 1;
    for (int k = 1; k <= max; k++)
    {
        for (int i = 1; i <= 3; i++)
        {
            int j = k - i;
            a[k] += a[j];
        }
    }

    for (int i = 0; i < T; i++)
    {
        cout << a[ns[i]] << "\n";
    }
    return 0;
}
