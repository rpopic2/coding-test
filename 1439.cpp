#include <iostream>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;

    int zeroes = 0;
    int ones = 0;

    char last = 0;
    int counter = 0;
    for (const char c : s) {
        if (last != c) {
            if (last == '1')
                ones += 1;
            else if (last == '0')
                zeroes += 1;
            counter = 0;
        }
        counter += 1;
        last = c;
    }

    int answer = std::max(zeroes, ones);
    std::cout << answer;
}

