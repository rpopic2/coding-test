#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int a_len, b_len;
    std::cin >> a_len >> b_len;

    std::vector<int> set(a_len);
    for (int i = 0; i < a_len; ++i) {
        std::cin >> set[i];
    }

    std::vector<int> setb(b_len);
    for (int i = 0; i < b_len; ++i) {
        std::cin >> setb[i];
    }

    std::sort(set.begin(), set.end());
    std::sort(setb.begin(), setb.end());

    int i = 0, j = 0;
    int answer = 0;
    while (i < a_len && j < b_len) {
        while (i < a_len && set[i] < setb[j]) answer++, ++i;
        while (j < b_len && set[i] > setb[j]) answer++, ++j;
        if (set[i] == setb[j]) ++i, ++j;
    }
    std::cout << answer + (b_len - j) + (a_len - i);
    std::cout << set.size();
}

