#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::deque<int> q(n);
    int ops = 0;
    for (int i = 1; i <= n; ++i) {
        q[i - 1] = i;
    }
    for (int i = 0; i < m; ++i) {
        int num;
        std::cin >> num;

        int j = 0;
        for (; j < q.size(); ++j) {
            if (q[j] == num)
                break;
            // printf("%d ", num);
        }

        // if at front
        int back_d = q.size() - j;
        if (back_d > j) {
            for (int k = 0; k < j; ++k) {
                int f = q.front();
                q.pop_front();
                q.push_back(f);
                ops++;
                // printf("op2 %d\n", j);
            }
        } else {
            for (int k = 0; k < back_d; ++k) {
                int f = q.back();
                q.pop_back();
                q.push_front(f);
                ops++;
                // printf("op3\n");
            }
        }
        q.pop_front();
    }

    std::cout << ops;
}

// 1 + 4 + 

