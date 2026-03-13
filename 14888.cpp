#include <iostream>
#include <vector>
#include <climits>

int n;
std::vector<int> as;
int maxx = INT_MIN;
int minx = INT_MAX;

union {
    struct {
        int add, sub, mul, div;
    };
    int arr[4];
} u;

void recurse(int i, int acc) {
    if (i >= n) {
        maxx = std::max(maxx, acc);
        minx = std::min(minx, acc);
        return;
    }
    int a = as[i];
    for (int j = 0; j < 4; ++j) {
        if (u.arr[j] == 0) {
            continue;
        }

        u.arr[j] -= 1;
        int result = acc;
        switch (j) {
        case 0: result += a; break;
        case 1: result -= a; break;
        case 2: result *= a; break;
        case 3: result /= a; break;
        }

        recurse(i + 1, result);
        u.arr[j] += 1;
    }
}

int main() {
    std::cin >> n;
    as = std::vector<int>(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> as[i];
    }

    std::cin >> u.add >> u.sub >> u.mul >> u.div;

    recurse(1, as[0]);

    std::cout << maxx << '\n' << minx << '\n';
}

