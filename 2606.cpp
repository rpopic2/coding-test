#include <iostream>
#include <vector>
#include <stack>

int main() {
    int num_computers;
    std::cin >> num_computers;
    int num_connections;
    std::cin >> num_connections;

    std::vector<std::vector<int>> graph(num_computers + 1, std::vector<int>(num_computers + 1));
    for (int i = 0; i < num_connections; ++i) {
        int a, b;
        std::cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    std::stack<int> stack;
    std::vector<int> visited(num_computers + 1, 0);
    stack.push(1);
    int infested = -1;
    while (!stack.empty()) {
        const int top = stack.top();
        stack.pop();
        if (visited[top])
            continue;
        visited[top] = true;
        infested += 1;

        const auto &g = graph[top];
        for (int i = 0; i < g.size(); ++i) {
            int x = g[i];
            // printf("top %d: %d(%d) ", top, x, visited[x]);
            if (x && !visited[i]) {
                stack.push(i);
            }
        }
        // printf("eol\n");
    }
    std::cout << infested;
}

