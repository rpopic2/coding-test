#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int a, b;
        std::cin >> a >> b;

        int ca = a;
        int cb = b;
        while (ca != cb) {
            if (ca < cb)
                ca += a;
            else if (cb < ca)
                cb += b;
        }
        std::cout << ca << '\n';
    }
}

