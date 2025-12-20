#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> not_heard_of(n);
    for (int i = 0; i < n; ++i) {
        std::string name;
        // std::cin >> name;
        // not_heard_of.insert(std::move(name));
        std::cin >> not_heard_of[i];
    }
    std::ranges::sort(not_heard_of);

    std::vector<std::string> answers;
    for (int i = 0; i < m; ++i) {
        std::string name;
        std::cin >> name;

        // if (not_heard_of.contains(name)) {
        // if (std::find(not_heard_of.begin(), not_heard_of.end(), name) != not_heard_of.end()) {
        if (std::binary_search(not_heard_of.begin(), not_heard_of.end(), name)) {
            answers.push_back(std::move(name));
        }
    }

    std::ranges::sort(answers);

    std::cout << answers.size() << '\n';
    for (const auto &s : answers) {
        std::cout << s << '\n';
    }
}

