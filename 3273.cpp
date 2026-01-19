#include <iostream>
#include <vector>

constexpr int SIZE = 100'001;
bool map[SIZE];

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        vec[i] = a;
        map[a] = true;
    }

    int x;
    std::cin >> x;

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        int a = vec[i];
        map[a] = false;
        int index = x - a;
        if (index >= 0 && index < SIZE && map[index]) {
            ++answer;
        }
    }
    std::cout << answer << '\n';
}

