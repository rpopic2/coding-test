#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<std::vector<short>> memo;
std::vector<short> track_memo;

int track(const std::vector<short> &m) {
    short biggest = 0;
    for (auto idx : m) {
        const auto &target = memo[idx];
        if (target.size() == 0)
            continue;
        if (track_memo[idx] == -1) {
            track_memo[idx] = track(target);
        }
        biggest = std::max(biggest, track_memo[idx]);
    }
    return biggest + 1;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    freopen
    std::cin >> n;

    if (n == 1) {
        std::cout << '1';
        return 0;
    }

    std::vector<short> arr(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    track_memo = std::vector<short>(n, -1);
    memo = std::vector<std::vector<short>>(n);
    for (size_t i = 0; i < n; ++i) {
        int a = arr[i];
        for (size_t j = i+1; j < n; ++j) {
            int b = arr[j];
            if (a < b) {
                memo[i].push_back(j);
            }
        }
    }

    std::vector<short> start(n);
    for (size_t i = 0; i < n; ++i) {
        start[i] = i;
    }
    std::cout << track(start) << '\n';
}

// 13 10 20 10 30 20 50 21 22 23 24 25 26 27
// 10 30 50 21 22 23 24 25 26 27
// 10 30 51 27 26 25 24 23 21
