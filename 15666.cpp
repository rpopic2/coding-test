#include <iostream>
#include <algorithm>

using vec = std::vector<int>;

vec nums;
vec bt;

void recurse(int depth, int start) {
    if (depth == 0) {
        // printf("depth 0\n");
        for (int x : bt) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
        return;
    }

    for (int i = start; i < nums.size(); ++i) {
        // printf("m-depth %d, %d\n", depth, i);
        bt.push_back(nums[i]);
        recurse(depth - 1, i);
        bt.pop_back();
    }

}

int main() {
    int n, m;
    std::cin >> n >> m;

    nums = vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    std::sort(nums.begin(), nums.end());
    auto new_end = std::unique(nums.begin(), nums.end());
    nums.erase(new_end, nums.end());

    recurse(m, 0);
}

