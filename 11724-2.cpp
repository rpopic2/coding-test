#include <iostream>
#include <vector>

using vec = std::vector<int>;
using mat = std::vector<vec>;

vec dsu;

int find(int x) {
    if (dsu[x] == x)
        return x;
    return dsu[x] = find(dsu[x]);
}

int merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return 0;
    dsu[y] = x;
    return 1;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;

    dsu = vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        dsu[i] = i;
    }

    int answer = n;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        answer -= merge(u, v);
    }

    std::cout << answer;
}

