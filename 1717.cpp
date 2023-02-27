/* 
 * /!\ This is not my final code! /!\
 *  See 1717-2.cpp for proper impementation that works in O(a(n))
 */

#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

constexpr auto NO = "NO";
constexpr auto YES = "YES";

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> union_map(n + 1);
    map<int, vector<int> *> mapp;
    for (int i = 0; i <= n; ++i) {
        union_map[i] = vector<int>(1, i);
        mapp[i] = &union_map[i];
    }

    int op;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> op >> a >> b;
        if (op == 0) {
            auto &va = *mapp[a];
            auto &vb = *mapp[b];

            vector<int> tmp(va.size() + vb.size());
            ranges::merge(va, vb, tmp.begin());

            //cout << '\n';
            auto *ptr = mapp[a];
            for (const auto &i : tmp) {
                mapp[i] = ptr;
            }
            *ptr = std::move(tmp);
        } else if (op == 1) {
            //cout << "mapp[" << a << "] = ";
            //for (const auto &i : *(mapp[a])) {
                //cout << i << ' ';
            //}
            auto result = ranges::includes(*mapp[a], initializer_list<int>{b});
            cout << (result ? YES : NO) << '\n';
        }
    }
}

