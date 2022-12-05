#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int score;
    cin >> score;
    score /= 10;
    score = min(score, 9);
    score = max(score, 5);
    char r =  9 - score + 'A';
    cout << r;
}
