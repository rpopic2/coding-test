#include <cstdio>
#include <limits>
#include <vector>

int main() {
    int n;
    std::scanf("%d", &n);

    std::vector<int> ropes(n);
    for (int i = 0; i < n; ++i) {
        std::scanf("%d", &ropes[i]);
    }
    std::sort(ropes.begin(), ropes.end());

    int max = 0;
    for (int i = 0; i < n; ++i) {
        int cur = (n - i) * ropes[i];
        max = std::max(max, cur);
    }
    std::printf("%d", max);
}

