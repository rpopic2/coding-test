#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <cmath>

class sorter {
    using T = std::map<int, int>::value_type;
    bool operator()(T lhs, T rhs) const {
        return lhs.second > rhs.second;
    }
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long acc = std::accumulate(numbers.begin(), numbers.end(), 0);
    double average = acc / (double)n;
    std::cout << (long long)std::round(average) << '\n';

    std::sort(numbers.begin(), numbers.end());
    int median = numbers[n / 2];
    std::cout << median << '\n';

    std::unordered_map<int, int> occurances;
    for (const int a : numbers) {
        occurances[a] += 1;
    }

    using map_value_t = std::pair<int, int>;
    std::vector<map_value_t> tmp(occurances.begin(), occurances.end());

    auto sorter = [](map_value_t a, map_value_t b) { return a.second > b.second; };
    std::sort(tmp.begin(), tmp.end(), sorter);

    // auto it_occurances = tmp.begin();
    // auto first_frequent = *it_occurances;
    // ++it_occurances;
    // auto second_frequent = *it_occurances;

    // for (auto &[k, v] : tmp) {
    //     std::printf("%d ,%d\n", k, v);
    // }

    auto it_tmp = tmp.begin();
    int value = it_tmp->second;
    for (; it_tmp != tmp.end(); ++it_tmp) {
        if (it_tmp->second == value)
            continue;
        else
            break;
    }

    if (tmp.size() <= 1) {
        std::cout << tmp.begin()->first << '\n';
    } else {
        std::sort(tmp.begin(), it_tmp, std::less());
        std::cout << (++tmp.begin())->first << '\n';
        std::cout << "other path\n";
    }

    // int most_frequent;
    // if (occurances.size() > 1 && first_frequent.second == second_frequent.second) {
    //     most_frequent = second_frequent.first;
    // } else {
    //     most_frequent = first_frequent.first;
    // }

    // std::cout << most_frequent << '\n';

    long range = *numbers.crbegin() - *numbers.cbegin();
    std::cout << range << '\n';
}

