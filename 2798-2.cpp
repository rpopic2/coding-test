#include <cstdio>
#include <algorithm>
#include <array>

int num_cards, limit, result_sum;
std::array<int, 100> nums;
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
    scanf("%d %d", &num_cards, &limit);
    for (int i = 0; i < num_cards; ++i)
    {
        scanf("%d", &nums[i]);
    }
    std::sort(nums.begin(), nums.end());

    max_sum(0, 0, 0);
    printf("%d", result_sum);
}
