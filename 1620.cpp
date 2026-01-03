#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <unordered_map>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> pokedex(n + 1);
    std::unordered_map<std::string, int> namedex;
    for (int i = 1; i <= n; ++i) {
        std::cin >> pokedex[i];
        namedex[pokedex[i]] = i;
    }

    for (int i = 0; i < m; ++i) {
        std::cin.get();
        auto peek = std::cin.peek();
        if (peek >= '0' && peek <= '9') {
            int index;
            std::cin >> index;
            std::cout << pokedex[index] << '\n';
        } else {
            std::string name;
            std::cin >> name;
            auto target = namedex[name];
            std::cout << target << '\n';
        }
    }
}

