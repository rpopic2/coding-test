// #include <iostream>
#include <stdio.h>
#include <bitset>

constexpr int SIZE = 100'0001;
// bool map[SIZE];


int main() {
    // std::cin.tie(nullptr)->sync_with_stdio(false);
    std::bitset<SIZE> map;

    int n;
    std::scanf("%d", &n);
    // std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int a;
        std::scanf("%d", &a);
        // std::cin >> a;
        map[a] = true;
    }

    int x;
    std::scanf("%d", &x);
    // std::cin >> x;

    int answer = 0;
    for (int i = 1; i < (x + 1) / 2; ++i) {
        int index = x - i;
        if (index < SIZE && map[i] && map[index]) {
            ++answer;
        }
    }
    std::printf("%d\n", answer);
    // std::cout << answer << '\n';
}

