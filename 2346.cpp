#include <iostream>
#include <vector>
#include <optional>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    struct balloon {
        int content; int no;
    };

    std::vector<std::optional<balloon>> balloons(n);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        balloons[i] = {x, i + 1};
    }

    int index = 0;
    int remain = n;
    while (remain) {
        auto [content, no] = balloons.at(index).value();
        std::cout << no << ' ';
        std::cout.flush();
        balloons[index].reset();
        --remain;
        if (remain == 0)
            break;

        while (content > 0) {
            --content;
            ++index;
            // printf("[%d]\n", index);
            while (!balloons.at(index % n).has_value()) {
                ++index;
                index %= n;
            }
        }
        while (content < 0) {
            ++content;
            if (index == 0)
                index = n;
            --index;
            // printf("[%d]\n", index);
            while (!balloons.at(index).has_value()) {
                if (index == 0)
                    index = n;
                --index;
                // printf("[%d]\n", index);
            }
        }
    }
    std::cout << '\n';
}

