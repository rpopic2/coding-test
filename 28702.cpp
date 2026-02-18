
#include <iostream>
#include <vector>

int main() {
    std::string s[3];
    std::cin >> s[0] >> s[1] >> s[2];

    int nums[3] = {0};

    for (int i = 0; i < 3; ++i) {
        int num = 0;
        try {
            num = std::stoi(s[i]);
        } catch (std::exception e){
            continue;
        }
        for (int j = i; j < 3; ++j) {
            nums[j] = num + j - i;
        }
        break;
    }

    int target = nums[2] + 1;

    if (target % 3 == 0 && target % 5 == 0) {
        std::cout << "FizzBuzz";
    } else if (target % 3 == 0) {
        std::cout << "Fizz";
    } else if (target % 5 == 0) {
        std::cout << "Buzz";
    } else {
        std::cout << target;
    }
}
