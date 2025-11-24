#include <iostream>
#include <vector>

struct dsu {
    explicit dsu(int n) : parents(n), size(n)
    {
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
    }

    auto find(int x) -> int {
        while (parents[x] != x) {
            parents[x] = parents[parents[x]];
            x = parents[x];
        }
        return x;
    }

    auto merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return;

        if (size[x] < size[y]) {
            std::swap(size[x], size[y]);
        }

        parents[y] = x;
        size[x] = size[x] + size[y];
    }

    std::vector<int> parents;
    std::vector<int> size;
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;

    dsu d(n + 1);
    for (int i = 0; i < m; ++i) {
        int op, a, b;
        std::cin >> op >> a >> b;
        if (op == 0) {
            d.merge(a, b);
        } else {
            std::cout << (d.find(a) == d.find(b) ? "YES" : "NO");
            std::cout << '\n';
        }
    }
}

