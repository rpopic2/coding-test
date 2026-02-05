#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 1; i <= n; ++i) {
        arr[i - 1] = i;
    }
    do {
        for (auto a : arr) {
            std::cout << a << ' ';
        }
        std::cout << '\n';
    } while (std::next_permutation(arr.begin(), arr.end()));
}

