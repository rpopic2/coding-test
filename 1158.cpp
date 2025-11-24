#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> circle(n);
    std::vector<bool> visited(n);
    for (int i = 0; i < n; ++i) {
        circle[i] = i + 1;
    }

    std::cout << '<';
    //
    // int visit_count = 0;
    // int index = 0;

    // while (visit_count < n) {
    //     for (int i = 0; i < k - 1; ++i) {
    //         while (visited[index]) {
    //             ++index;
    //             index %= n;
    //         }
    //     }
    //     std::cout << circle[index] << ", ";
    //     visited[index] = true;
    //     visit_count += 1;
    // }

    int index = 0;
    for (int i = 0; i < n; ++i) {
        index += k - 1;
        index %= circle.size();
        if (i != 0) {
            std::cout << ", ";
        }
        std::cout << circle[index];
        circle.erase(std::next(circle.begin(), index));
        // std::printf("at %d, ", index);
        // std::cout << circle.size();
    }

    // auto it = circle.begin();
    // auto end = circle.end();
    // while (it != end) {
    //     std::cout << '.' << circle.size() << '.';
    //     for (int i = 0; i < 2; ++i) {
    //         ++it;
    //         if (it == end) {
    //             it = circle.begin();
    //         }
    //     }
    //     std::cout << *it << std::endl;
    //     circle.erase(it);
    //     std::cout << ", ";
    // }

    std::cout << ">\n";
}
/*
    auto it = circle.begin();
    while (!circle.empty()) {
        for (int i = 0; i < 2; ++i) {
            ++it;
            if (it == circle.end()) {
                it = circle.begin();
            }
        }
        std::cout << *it << std::endl;
        circle.erase(it);
        std::cout << ", ";
    }

    */
