#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int x;
    std::cin >> x;

    constexpr int start = 64;

    std::vector<int> sticks;
    sticks.push_back(start);

    while (true) {
        int acc = std::accumulate(sticks.begin(), sticks.end(), 0);
        if (acc <= x)
            break;

        auto last_it = --sticks.end();
        auto half = *last_it / 2;
        *last_it = half;
        sticks.push_back(half);

        int acc2 = std::accumulate(sticks.begin(), --sticks.end(), 0);
        if (acc2 >= x) {
            sticks.pop_back();
        }
    }

    std::cout << sticks.size() << '\n';
}

