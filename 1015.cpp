#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> b = a;
    std::sort(b.begin(), b.end());

    std::vector<int> p(n, -1);

    for (int i = 0; i < n; ++i) {
        auto it = std::find(b.begin(), b.end(), a[i]);
retry:
        auto d = std::distance(b.begin(), it);
        auto dup = std::find(p.begin(), p.end(), d);
        if (dup != p.end()) {
            it = std::find(it + 1, b.end(), a[i]);
            goto retry;
        }
        p[i] = d;
    }

    for (int x : p) {
        std::cout << x << ' ';
    }
}

