#include <iostream>

int read_one_people() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int acc = 0;
    int buf;
    for (int i = 0; i < 4; ++i) {
        std::cin >> buf;
        acc += buf;
    }
    return acc;
}

int main() {
    int max_score = 0;
    int max_index = 0;
    for (int i = 0; i < 5; ++i) {
        int buf = read_one_people();
        if (buf > max_score) {
            max_score = buf;
            max_index = i + 1;
        }
    }

    std::cout << max_index << ' ' << max_score << '\n';
}
