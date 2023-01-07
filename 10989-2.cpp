#include <iostream>
#include <array>
#include <algorithm>
#include <string>
using namespace std;
constexpr int MAX_IN = 10'000 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    array<string, MAX_IN> arr;
    fill(arr.begin(), arr.end(), "");
    for (int c, i = 0; i < N; ++i) {
        cin >> c;
        arr[c] += to_string(c) + '\n';
    }
    for (int i = 0; i < MAX_IN; ++i) {
        cout << arr[i];
    }
}
