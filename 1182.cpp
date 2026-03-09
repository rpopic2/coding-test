#include <iostream>

int n, s;
int nums[21];

int sum = 0;
int count = 0;
int sel = 0;

void bt(int index) {
    if (index == n) {
        if (sum == s) {
            count += 1;
        }
        return;
    }

    sum += nums[index];
    // sel += 1;
    bt(index + 1);

    sum -= nums[index];
    // sel -= 1;
    bt(index + 1);
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cin >> n >> s;

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        nums[i] = x;
    }

    bt(0);
    if (s == 0)
        count -= 1;
    std::cout << count << '\n';
}

