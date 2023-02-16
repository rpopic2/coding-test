#include <iostream>
#include <array>
using namespace std;

constexpr int PAY = 1'000;

constexpr array<int, 6> coins {
    500, 100, 50, 10, 5, 1
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int price;
    cin >> price;
    int change = PAY - price;

    int coins_count = 0;
    while (change != 0) {
        for (const auto &c : coins) {
            int diff = change - c;
            if (diff < 0) continue;
            change = diff;
            coins_count += 1;
            break;
        }
    }

    cout << coins_count << '\n';
}

