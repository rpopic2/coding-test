#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.ignore(5, '\n');
    vector<int> v;
    for (int c; cin >> c;)
    {
        v.push_back(c);
    }
    float m = *max_element(v.begin(), v.end());
    float average, sum = 0;
    for (auto &i : v)
    {
        sum += i / m * 100;
    }
    average = sum / v.size();
    cout << fixed << average;
}
