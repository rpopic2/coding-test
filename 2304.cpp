#include <iostream>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
bool comph(const pair<int, int> &lhs, const pair<int, int> &rhs) {
    return lhs.second < rhs.second;
}
int get_extent(pair<int, int> lhs, pair<int, int> rhs) {
    return (rhs.first - lhs.first) * lhs.second;
}
int rget_extent(pair<int, int> lhs, pair<int, int> rhs) {
    return (lhs.first - rhs.first) * lhs.second;
}
int main() {
    int N;
    cin >> N;
    set<pair<int, int>> vec;
    for (int l, h, i = 0; i < N; ++i) {
        cin >> l >> h;
        vec.insert(pair<int, int>(l, h));
    }
    auto max_ptr = std::max_element(vec.begin(), vec.end(), comph);
    pair<int, int> current_max{0, 0};
    int acc = (max_ptr++)->second;
    for (auto iter = vec.begin(); iter != max_ptr; ++iter) {
        if (comph(current_max, *iter)) {
            acc += get_extent(current_max, *iter);
            current_max = *iter;
        }
    }
    --max_ptr;
    auto back_ptr = --vec.end();
    current_max = {back_ptr->first + 1, 0};
    for (auto iter = back_ptr; iter != max_ptr; --iter) {
        if (comph(current_max, *iter)) {
            acc += rget_extent(current_max, *iter);
            current_max = *iter;
        }
    }
    acc += rget_extent(current_max, *max_ptr);
    cout << acc;
}

