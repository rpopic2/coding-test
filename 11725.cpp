#include <iostream>
#include <vector>
#include <bitset>

using vec = std::vector<int>;
using mat = std::vector<vec>;

mat tree;
vec result;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    tree = mat(n + 2);
    result = vec(n + 2);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        std::cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vec stack;
    std::bitset<100'002> visited;
    stack.push_back(1);

    while (!stack.empty()) {
        int back = stack.back();
        stack.pop_back();
        visited[back] = true;
        auto nodes = tree[back];
        for (int n : nodes) {
            if (visited[n])
                continue;
            stack.push_back(n);
            result[n] = back;
        }
    }

    for (int i = 2; i <= n; ++i) {
        std::cout << result[i] << '\n';
    }
}

