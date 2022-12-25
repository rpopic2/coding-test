#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    vec.resize(4);
    for (int i = 0; i < 4; ++i)
    {
        cin >> vec[i];
    }
    vec[2] -= vec[0];
    vec[3] -= vec[1];
    auto result = *min_element(vec.begin(), vec.end());
    cout << result;
}
