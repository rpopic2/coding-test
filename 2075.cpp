#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    std::cin >> n;

    std::vector<int> nums(n*n);
    for (int i = 0; i < n*n; ++i) {
        std::cin >> nums[i];
    }
    std::sort(nums.begin(), nums.end(), std::greater<int>());

    std::cout << nums[n-1] << '\n';
}

