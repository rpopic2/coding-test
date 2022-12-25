#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<size_t> vec;
    size_t input_n;
    cin >> input_n;
    vec.resize(input_n);
    vec[0] = 0;
    vec[1] = 1;
    for (size_t i = 2; i <= input_n; ++i)
    {
        vec[i] = vec[i - 1] + vec[i - 2];
    }
    cout << vec[input_n];
}
