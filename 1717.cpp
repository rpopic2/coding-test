#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <ranges>
using namespace std;

constexpr auto NO = "NO";
constexpr auto YES = "YES";

int main() {
    int n, m;
    cin >> n >> m;

    auto b = n <=> m;
    map<int, vector<int>> union_map;
    for (int i = 0; i <= n; ++i) {
        union_map[i] = vector<int>(1, i);
    }

    for (const auto &i : std::views::iota(0, m)) {

    }
}
