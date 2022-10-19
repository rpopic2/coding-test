#include <iostream>
#include <vector>
using namespace std;

const vector<int> PIECES_INFO = {1, 1, 2, 2, 2, 8};
size_t length = PIECES_INFO.size();
int main()
{
    int temp;
    vector<int> inputs;
    for (int i = 0; i < length; i++)
    {
        cin >> temp;
        inputs.push_back(temp);
    }

    for (int i = 0; i < length; i++)
    {
        int j = PIECES_INFO[i] - inputs[i];
        cout << j << " ";
    }

    return 0;
}