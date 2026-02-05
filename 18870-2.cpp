
#include <iostream>
#include <vector>
#include <algorithm>

struct pair {
    int val;
    int index;

};

bool cmp(const std::pair<int, int> lhs, const std::pair<int, int> rhs) {
    return lhs.first < rhs.first;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> x(n);
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        x[i] = {num, i};
    }
    // std::vector<int> x_prime = x;
    std::sort(x.begin(), x.end(), cmp);

    std::vector<int> x_prime(n);
    int count = 0;
    int prev = x[0].first;
    for (auto [val, index] : x) {
        if (prev != val) {
            count += 1;
        }
        prev = val;
        x_prime[index] = count;
    }

    for (int num : x_prime) {
        std::cout << num << ' ';
    }
}

