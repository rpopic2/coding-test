#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class hashmap {
    using hash_t = int;
public:
    hashmap() : map(200'000) { }

    inline hash_t &operator[](std::string &s) noexcept {
        return map[s];
    }

    inline hash_t insert_if_no_value(std::string &s) noexcept {
        if (map[s] != 0)
            return map[s];
        return map[s] = hash(s);
    }

    inline void clear() noexcept {
        map.clear();
    }
private:
    std::unordered_map<std::string, hash_t> map;
    int hash(std::string &s) noexcept {
        int hash = 0;
        for (auto &c : s)
            hash = (hash * 31 + c) % 200'000;
        return hash;
    }
};

class disjoint_set {
public:
    disjoint_set() : data(200'000, -1) { }

    inline int &search(int &s) noexcept {
        if (data[s] == -1)
            return s;
        return data[s] = search(data[s]);
    }

    inline void merge(int &lhs, int &rhs) noexcept {
        auto &root_lhs = search(lhs);
        auto &root_rhs = search(rhs);
        if (root_lhs == root_rhs)
            return;
        data[root_rhs] += data[root_lhs];
        data[root_lhs] = root_rhs;
    }

    inline int count_group_members(int &s) noexcept {
        return -data[search(s)];
    }

    inline void clear() noexcept {
        std::fill(data.begin(), data.end(), -1);
    }
private:
    std::vector<int> data;
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int tc_count;
    std::cin >> tc_count;

    disjoint_set set;
    hashmap map;

    while (tc_count--) {
        int F;
        std::cin >> F;

        while (F--) {
            std::string friend1, friend2;
            std::cin >> friend1 >> friend2;
            auto hash1 = map.insert_if_no_value(friend1);
            auto hash2 = map.insert_if_no_value(friend2);
            set.merge(hash1, hash2);
            std::cout << set.count_group_members(hash1) << '\n';
        }

        set.clear();
        map.clear();
    }
}
