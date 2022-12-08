#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    int tmp;
    while (cin >> tmp)
    {
        v.push_back(tmp);
    }
    int* begin = &v[0];
    int* max = max_element(v.begin(), v.end()).base();
    cout << *max << '\n' << max - begin + 1;
}
