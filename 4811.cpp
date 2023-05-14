#include <iostream>
#include <vector>

class tablature
{
    using u64 = unsigned long long;
    using size_type = std::vector<u64>::size_type;
public:
    tablature(tablature::size_type size) : dp(size + 1, std::vector<u64>()), sum_memo(size + 1, 0) {
        sum_memo[1] = 1;
        dp[0].push_back(0);
        dp[1].push_back(1);
    }

    u64 tab(int n) {
        if (n == 1)
            return 1;
        auto &cur_dp = dp[n];

        if (!sum_memo[n - 1]) {
            tab(n - 1);
        }
        u64 acc = sum_memo[n - 1];
        cur_dp.push_back(acc);
        acc += acc;

        int nm2 = n - 2;
        for (int i = 0; i < nm2; ++i) {
            u64 result = range_acc(dp[n - 1], i, nm2);
            cur_dp.push_back(result);
            acc += result;
        }

        sum_memo[n] = acc;
        return acc;
    }
private:
    // end is not inclusive
    u64 range_acc(const std::vector<u64> &target, int begin, int end) {
        u64 acc = 0;
        for (; begin < end; ++begin) {
            acc += target[begin];
        }
        return acc;
    }

    std::vector<std::vector<u64>> dp;
    std::vector<u64> sum_memo;
};



int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    auto tab = tablature(30);

    while (true) {
        int input;
        std::cin >> input;
        if (input == 0)
            break;

        std::cout << tab.tab(input) << '\n';
    }
}
