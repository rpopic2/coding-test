#include <iostream>
#include <vector>

int accum(const std::vector<int> &target) {
    int acc = 0;
    for (const auto i : target) {
        acc += i;
    }
    return acc;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::vector<std::vector<int>> dp;
    std::vector<int> count;

    dp.emplace_back(std::vector<int>(1));
    dp[0][0] = 1;
    count.push_back(1);

    dp.emplace_back(std::vector<int>(2));
    dp[1][0] = 1;
    dp[1][1] = 1;
    count.push_back(accum(dp[1]));

    dp.emplace_back(std::vector<int>(3));
    //dp[2][0] = count[

    while (true) {
        int input;
        std::cin >> input;
        if (input == 0)
            break;



    }

}

