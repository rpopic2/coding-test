#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sorter(vector<int> v, vector<int> w)
{
    int sv = v[0] - v[1];
    int sw = w[0] - w[1];
    if (sv == sw) return v[0] > w[0];
    else return sv > sw;
}
int solution(int k, vector<vector<int>> dungeons) {
    int r = 0;
    int rr = 0;
    
    int curk = k;
    sort(dungeons.begin(), dungeons.end(), sorter);
    for (auto& d : dungeons)
    {
        if (curk < d[0]) continue;
        curk -= d[1];
        r++;
    }
    
    curk = k;
    reverse(dungeons.begin(), dungeons.end());
    for (auto& d : dungeons)
    {
        if (curk < d[0]) continue;
        curk -= d[1];
        rr++;
    }
    
    int answer = max(r, rr);
    
    return r;
}
