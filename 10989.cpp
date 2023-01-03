#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
constexpr int MAX_IN = 10'000 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    array<int, MAX_IN> arr;
    fill(arr.begin(), arr.end(), 0);
    for (int c, i = 0; i < N; ++i) {
        cin >> c;
        ++arr[c];
    }
    for (int i = 0; i < MAX_IN; ++i) {
        int repeat = arr[i];
        for (int j = 0; j < repeat; ++j) {
            cout << i << '\n';
        }
    }
}
