#include <iostream>
#include <vector>
#include <algorithm>

int num_cards, limit, result_sum;
std::vector<int> nums;
void max_sum(const int level, const int index, const int last_result)
{
    int search_till = num_cards - (2 - level);
    for (int i = index; i < search_till; ++i)
    {
        int cur_sum = last_result + nums[i];
        if (cur_sum > limit) return;
        if (level == 2) result_sum = std::max(result_sum, cur_sum);
        else max_sum(level + 1, i + 1, cur_sum);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> num_cards >> limit;
    for (int c, i = num_cards; i--;)
    {
        std::cin >> c;
        nums.push_back(c);
    }
    std::sort(nums.begin(), nums.end());

    max_sum(0, 0, 0);
    std::cout << result_sum;
}
