#include <iostream>
#include <algorithm>
#include <array>
constexpr int MAX_INPUT = 5000;

int main()
{
    std::array<int, MAX_INPUT> results{ 0 };
    int n_input;
    std::cin >> n_input;

    results[3] = 1;
    results[5] = 1;

    for (int i = 5 + 1; i <= n_input; ++i)
    {
        int m_three = results[i - 3];
        int m_five = results[i - 5];
        int tmp;
        int min = std::min(m_three , m_five);
        if (m_three == m_five && m_three == 0) continue;
        if (min == 0) tmp = std::max(m_five, m_three);
        else tmp = min;
            results[i] = ++tmp;
    }
    int answer = results[n_input];
    if (answer == 0) answer = -1;

    std::cout << answer;
}
