#include <iostream>
#include <queue>
#include <vector>

bool is_valid(int pos) {
    return pos >= 0 && pos <= 100'000;
}

struct info {
    int pos; int turn;
};

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<bool> visited(100'001);
    std::queue<info> q;
    q.push({n, 0});
    visited[n] = true;

    while (!q.empty()) {
        auto [back, turn] = q.front();
        q.pop();
        if (back == k) {
            std::cout << turn;
            return 0;
        }

        auto try_push = [&visited, &q, turn, k](int target) mutable {
            if (!is_valid(target)) {
                return;
            }
            if (target == k) {
                std::cout << turn + 1;
                exit(0);
            }
            if (visited[target])
                return;
            visited[target] = true;
            q.push({target, turn + 1});
            // printf("push: %d\n", target);

        };
        try_push(back + 1);
        try_push(back - 1);
        try_push(back * 2);
        // printf("\n");
    }
}

