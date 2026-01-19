#include <iostream>
#include <cstdint>
#include <vector>


enum cell {
    EMPTY = -1, NOT_RIPE = 0, RIPE = 1
};

using i8 = int;
using vec = std::vector<i8>;
using mat = std::vector<vec>;

int m, n;
mat storage;
mat storage_tmp;
bool flag;

void print() {
    std::cout << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << storage[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

const std::pair<int, int> DIR[] = {
    { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 }
};

bool is_valid(int x, int y) {
    return x >= 0 && y >= 0
        && x < n && y < m;
}

void advance(const int x, const int y) {
    for (auto [dx, dy] : DIR) {
        auto nx = x + dx;
        auto ny = y + dy;
        if (!is_valid(nx, ny))
            continue;
        if (storage_tmp[nx][ny] == NOT_RIPE) {
            storage_tmp[nx][ny] = RIPE;
            flag = true;
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cin >> m >> n;

    storage = mat(n, vec(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> storage[i][j];
        }
    }
    storage_tmp = storage;

    int answer = 0;
    while (true) {
        flag = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                auto tomato = storage[i][j];
                if (tomato == RIPE)
                    advance(i, j);
            }
        }
        if (!flag) {
            break;
        }

        storage = storage_tmp;
        ++answer;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            auto tomato = storage[i][j];
            if (tomato == NOT_RIPE) {
                std::cout <<"-1\n";
                return 0;
            }
        }
    }
    std::cout << answer << '\n';
}

