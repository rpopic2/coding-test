#include <iostream>
#include <queue>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::queue<int> q;

    for (int i = 0; i < n; ++i) {
        std::string op;
        std::cin >> op;

        if (op == "push") {
            int arg;
            std::cin >> arg;
            q.push(arg);
            continue;
        } else if (op == "pop") {
            if (q.empty()) {
                std::cout << "-1";
            } else {
                int front = q.front();
                q.pop();
                std::cout << front;
            }
        } else if (op == "size") {
            std::cout << q.size();
        } else if (op == "empty") {
            std::cout << (q.empty() ? '1' : '0');
        } else if (op == "front") {
            if (q.empty())
                std::cout << "-1";
            else
                std::cout << q.front();
        } else if (op == "back") {
            if (q.empty())
                std::cout << "-1";
            else
                std::cout << q.back();
        }
        std::cout << '\n';
    }
}

