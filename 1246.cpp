#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    struct balloon {
        int content; int no;
    };

    std::vector<balloon> balloons(n);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        balloons[i] = {x, i + 1};
    }

    int index = 0;
    int next = 0;
    while (!balloons.empty()) {
        balloon b = balloons[index];
        next = b.content;
        balloons.erase(std::next(balloons.begin(), index));
        index = (index + next) % std::max(balloons.size(), size_t(1));
        std::cout << b.no << ' ';
    }
    std::cout << '\n';
}

