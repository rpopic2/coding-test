#include <iostream>
#include <array>
#include <algorithm>

int main() {
    std::array<int, 5> numbers;

    for (int i = 0; i < 5; ++i) {
        std::cin >> numbers[i];
    }

    int average = 0;
    for (const auto num : numbers) {
        average += num;
    }
    average /= 5;

    std::sort(numbers.begin(), numbers.end());
    int median = numbers[2];

    std::cout << average << '\n' << median << '\n';
}
