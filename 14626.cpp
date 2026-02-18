#include <iostream>
#include <vector>

int checksum(const std::vector<int> nums) {
    int checksum = 0;
    for (int i = 0; i < 12; ++i) {
        if (i % 2 == 0) {
            checksum += nums[i];
        } else {
            checksum += nums[i] * 3;
        }
    }
    checksum = 10 - checksum % 10;
    if (checksum == 10)
        return 0;
    return checksum;
}

int main() {
    std::vector<int> nums(13);
    int star = 0;
    for (int i = 0; i < 13; ++i) {
        char c;
        std::cin >> c;
        if (c == '*') {
            star = i;
            continue;
        }
        nums[i] = c - '0';
    }
    // nums[star] = 9;
    // std::cout << checksum(nums) << '\n';

    for (int i = 0; i < 10; ++i) {
        nums[star] = i;
        auto check = checksum(nums);
        // printf("star: %i, check: %d, back: %d\n", nums[star], check, nums.back());
        if (check == nums.back()) {
            std::cout << i;
            return 0;
        }
    }
    std::cout <<"nf\n";
}
//9788968322273

//9950549032103
