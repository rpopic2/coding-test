#include <iostream>
#include <vector>
#include <set>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::set<std::string> peoples;

    for (int i = 0; i < n; ++i) {
        std::string name, op;
        std::cin >> name >> op;
        if (op == "enter")
            peoples.insert(name);
        else
            peoples.erase(name);
    }

    for (auto it = peoples.rbegin(); it != peoples.rend(); ++it) {
        std::cout << *it << '\n';
    }
}

