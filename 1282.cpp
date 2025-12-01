#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int start, end;
    std::cin >> start >> end;

    std::vector<int> arr;

    int num = 1;
    while (true) {

        for (int i = 0; i < num; ++i) {
            arr.push_back(num);
        }
        num += 1;
        if (arr.size() >= 1000)
            break;
    }

    int sum = std::accumulate(std::next(arr.begin(), start - 1), std::next(arr.begin(), end), 0);

    std::cout << sum;
}

