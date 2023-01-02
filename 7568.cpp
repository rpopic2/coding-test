#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
constexpr char WS = ' ';

bool comp(const pair<int,int> &lhs, const pair<int,int> &rhs)
{
    if (lhs.first > rhs.first && lhs.second > rhs.second) return true;
    return false;
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> vec;
    vec.resize(N);
    int a, b;
    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b;
        vec[i] = pair(a, b);
    }
    vector<pair<int, int>> orig_vec = vec;
    sort(vec.begin(), vec.end(), comp);
    vector<int> result;
    result.reserve(N);

    int rank = 1;
    for (int i = 0; i < N; ++i)
    {
        int same_cnt = 0;
        auto iter = vec.begin() + i;
        for (;;)
        {
            if (comp(*iter, *++iter)) break;
            if (iter == vec.end()) break;
            ++same_cnt;
        }
        for (int j = same_cnt + 1; j--;) result.push_back(rank);
        i += same_cnt;
        rank += same_cnt + 1;
    }
    for (const auto &e : orig_vec) {
        auto p = find(vec.begin(), vec.end(), e);
        auto d = distance(vec.begin(), p);
        cout << result[d] << WS;
    }
}
// for x in vec:
    // for each elem in vec:
        // if elem is greater than x:
            // add to next_search_vec;
            //if no element greater than x:
            //      rank of x is 1;
            //else if one element exists:
            //      reank of x is 2, 
            //else do recursion to next_search_vec;
        //fi
    //done
//done

//for pair in vec
//let result: vec
//
//let cur_rank = 1;
//procedure:
//get max elements in the vec
//for each those elements:
//  set result(vec) of repective elements to cur_rank, cur_rank += count of them
//  remove them from vec;
//end
