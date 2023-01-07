#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int K;
    cin >> K;
    vector<int> vec;
    vec.resize(K);
    for (int c; cin >> c;) {
        if (c) {
            vec.push_back(c);
        }
        else vec.pop_back();
    }
    int acc = 0;
    for (const auto &i : vec) {
        acc += i;
    }
    cout << acc;
}
