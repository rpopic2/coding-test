#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<bool> ok(N + 1);

    int cost = 0;
    for (int i = 0; i < N; ++i) {
        int nth;
        std::cin >> nth;
        if (nth > N || ok[nth]) {
            cost += i + 1;
        } else {
            ok[nth] = true;
        }
    }

    std::cout << cost << '\n';
}

