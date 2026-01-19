#include <iostream>
#include <unordered_map>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::size_t n, m;
    std::cin >> n >> m;

    std::unordered_map<std::string, std::string> map(n);

    for (int i = 0; i < n; ++i) {
        std::string key, value;
        std::cin >> key >> value;
        map.emplace(std::move(key), std::move(value));
    }

    for (int i = 0; i < m; ++i) {
        std::string query;
        std::cin >> query;
        std::cout << map[query] << '\n';
    }
}

