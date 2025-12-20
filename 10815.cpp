#include <iostream>
#include <vector>
#include <algorithm>

bool bsearch2(const std::vector<int> &cards, int query) {
    int begin = 0;
    int end = cards.size();

    while (true) {
        auto half = (begin + end) / 2;
        auto target = cards[half];

        if (query == target)
            return true;
        if (end - begin <= 1)
            return false;
        else if (query > target) {
            begin = half;
        } else {
            end = half;
        }
    }

}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> cards[i];
    }
    std::sort(cards.begin(), cards.end());

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        int query;
        std::cin >> query;

        bool found = bsearch2(cards, query);

        if (found) {
            std::cout << 1;
        } else {
            std::cout << 0;
        }
        std::cout << ' ';
    }
}

