#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<bool> not_prime(n + 1);
    not_prime[1] = true;
    for (int i = 2; i < n + 1; ++i) {
        for (int j = 2; j * i < n + 1; ++j) {
            not_prime[j * i] = true;
        }
    }

    int tmp = n;
    std::vector<int> answer;
    for (int i = 2; i < n + 1; ++i) {
        if (not_prime[i]) {
            continue;
        }
        while (tmp % i == 0) {
            answer.push_back(i);
            tmp /= i;
        }
    }

    for (int x : answer) {
        std::cout << x << '\n';
    }
}

