#include <iostream>
#include <unordered_set>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int a_len, b_len;
    std::cin >> a_len >> b_len;

    std::unordered_set<int> set(a_len);
    for (int i = 0; i < a_len; ++i) {
        int x;
        std::cin >> x;
        set.insert(x);
    }

    for (int i = 0; i < b_len; ++i) {
        int x;
        std::cin >> x;
        if (set.contains(x)) {
            set.erase(x);
        } else {
            set.insert(x);
        }
    }

    std::cout << set.size();
}

