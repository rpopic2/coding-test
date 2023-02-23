#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
using namespace std;

constexpr auto NO = "NO";
constexpr auto YES = "YES";


class disjoint_set {

public:
    disjoint_set(int size) : parents(size) {
        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    int get_root(int n) noexcept {
        if (parents[n] == n) {
            return n;
        }
        return parents[n] = get_root(parents[n]);
    }

    void merge(int a, int b) noexcept {
        int root_a = get_root(a);
        int root_b = get_root(b);
        if (root_a == root_b)
            return;
        parents[root_a] = root_b;
    }
private:
    vector<int> parents;
};


int main() {
    //read input
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    disjoint_set set(N + 1);

    int op;
    int a, b;
    while (M--) {
        cin >> op >> a >> b;

        // operation 0: union
        if (op == 0) {
            set.merge(a, b);

        // operation 1: includes
        } else if (op == 1) {
            bool includes = set.get_root(a) == set.get_root(b);
            cout << (includes ? YES : NO) << '\n';
        }
    }
}
