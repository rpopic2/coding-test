#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <unordered_map>

class disjoint_set {
    using string = std::string;
    using pair = std::pair<string, int>;

public:
    disjoint_set() : map(200'000) { }
    // Search for root node for given string
    string &search(string &s) noexcept {
        if (map[s].first == s)
            return s;
        return map[s].first = search(map[s].first);
    }

    // Merge two nodes
    inline void merge(string &lhs, string &rhs) noexcept {
        auto &root_lhs = search(lhs);
        auto &root_rhs = search(rhs);
        if (root_lhs == root_rhs)
            return;
        map[root_rhs].second += map[root_lhs].second;
        map[root_lhs].first = root_rhs;
    }

    // Inseart a node if value does not exist
    inline void insert_if_no_value(string &s) noexcept {
        if (map[s].second != 0)
            return;
        map[s] = {s, 1};
    }

    inline int count_group_members(string &s) noexcept {
        return map[search(s)].second;
    }

    inline void clear() noexcept {
        map.clear();
    }

private:
    std::unordered_map<string, pair> map;
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int tc_count;
    std::cin >> tc_count;

    disjoint_set set;
    while (tc_count--) {
        int F;
        std::cin >> F;

        while (F--) {
            std::string friend1, friend2;
            std::cin >> friend1 >> friend2;

            set.insert_if_no_value(friend1);
            set.insert_if_no_value(friend2);

            set.merge(friend1, friend2);

            std::cout << set.count_group_members(friend1) << '\n';
        }
        set.clear();
    }
}
