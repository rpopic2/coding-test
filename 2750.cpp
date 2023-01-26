#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (auto &i : numbers) {
        cin >> i;
    }
    sort(numbers.begin(), numbers.end());
    for (const auto &i : numbers) {
        cout << i << '\n';
    }
}
