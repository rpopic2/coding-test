#include <queue>
#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_count;
    std::cin >> testcase_count;

    for (int i = 0; i < testcase_count; ++i) {
        int n, m;
        std::cin >> n >> m;

        using pair = std::pair<int, int>;
        auto comp = [](const pair &lhs, const pair &rhs) -> bool {
            if (lhs.first == rhs.first)
                return lhs.second < rhs.second;
            return lhs.first > rhs.first;
        };
        std::priority_queue<pair, std::vector<pair>, decltype(comp)> queue;

        for (int j = 0; j < n; ++j) {
            int priority;
            std::cin >> priority;
            queue.emplace(priority, j);
        }
        // FIRST IS PRIORITY
        // SECOND IS INDEX
        for (int j = 0; j < n; ++j) {
            // std::printf("(%d, %d)[%d]{%d}\n", queue.top().first, queue.top().second, m, (queue.top().first) == m);
            if (queue.top().second == m) {
                std::cout << j + 1 << std::endl;
                break;
            }
            queue.pop();
        }
    }
}

