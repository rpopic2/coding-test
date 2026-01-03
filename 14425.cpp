#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;

    std::unordered_set<std::string> s;
    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        s.insert(str);
    }

    int counter = 0;
    for (int i = 0; i < m; ++i) {
        std::string query;
        std::cin >> query;
        if (s.contains(query)) {
            counter += 1;
        }
        // counter += s.contains(query);
    }

    std::cout << counter;
}

