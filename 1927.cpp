#include <iostream>
#include <vector>
#include <queue>

using uint = unsigned int;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint n;
    std::cin >> n;

    std::priority_queue<uint, std::vector<uint>, std::greater<uint>> pq;

    for (int i = 0; i < n; ++i) {
        uint x;
        std::cin >> x;

        if (x == 0) {
            if (pq.empty()) {
                std::cout << "0\n";
                continue;
            }

            std::cout << pq.top() << '\n';
            pq.pop();
            continue;
        }
        pq.push(x);
    }
}

