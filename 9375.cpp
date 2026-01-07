#include <iostream>
#include <numeric>
#include <vector>
#include <unordered_map>

std::vector<int> values;
int acc = 0;

std::vector<int> elems;
std::vector<bool> visited;

void bt(int depth, int start, int n) {
    if (depth == n) {
        // acc += std::accumulate(elems.begin(), elems.end(), acc);
        if (elems.size() == 0)
            return;

        int mulacc = 1;
        for (auto x : elems) {
            // std::cout << x << ' ';
            mulacc *= x;
        }
        // std::cout << "mulacc: " << mulacc << '\n';
        acc += mulacc;
        // std::cout << '\n';

        return;
    }

    for (int i = start; i < values.size(); ++i) {
        if (visited[i])
            continue;
        visited[i] = true;
        elems.push_back(values[i]);
        bt(depth + 1, i, n);
        elems.pop_back();
        visited[i] = false;
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::unordered_map<std::string, int> map;

        for (int i = 0; i < n; ++i) {
            std::string name, part;
            std::cin >> name >> part;
            map[part] += 1;
        }

        acc = 1;
        values.clear();
        for (const auto &[_, v] : map) {
            // values.push_back(v);
            // std::cout << "value : " << v << '\n';
            acc *= v + 1;
        }
        // visited = std::vector<bool>(values.size());
        //
        // for (int i = 1; i <= values.size(); ++i) {
        //     bt(0, 0, i);
        // }

        // std::cout << "ans: ";
        std::cout << acc - 1 << '\n';
    }
}

