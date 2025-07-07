#include <iostream>

int main() {
    constexpr int SIZE = 8000;
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    int acc = 0;
    std::vector<int> counts(SIZE);

    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        counts[a + 4000] += 1;

        acc += a;
    }

    int median = 0;
    for (int i = 0; i < SIZE; ++i) {
        int a = counts[i];
        if (a == 0)
            continue;
        int number = i - 4000;
        
    }
}

