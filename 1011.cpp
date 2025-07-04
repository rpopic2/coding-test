#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int x, y;
        std::cin >> x >> y;
        int diff = y - x;
        int d = sqrt(diff);
        int moves = 2 * d;
        if (pow(d, 2) == diff) {
            moves -= 1;
        }
        if (diff > d * (d + 1)) {
            moves += 1;
        }
        std::cout << moves;
    }
}

// for case 0..1 -> 1
// 1:1
//
// for case 0..2 -> 2
// 1:1, 1:2
//
// for case 0..3 -> 3
// 1:1, 1:2, 1:3
//
// for case 0..4 -> 3
//
// 1:1, 2:3, 1:4
//
// for case 0..5 -> 4
// 
// 1:1, 2:3, 1:4, 1:5
//
// for case 0..6 -> 4
//
// 1:1, 2:3, 2:5, 1:6
//
// for case 0..7 -> 5
//
// 1:1: 2:3, 2:5, 1:6, 1:7
//
// for case 0..8 -> 5
//
// 1:1: 2:3, 2:5, 2:7, 1:8
//
// for case 0..9 -> 5
//
// 1:1: 2:3, 3:6, 2:8, 1:9
//
// for case 0..10 -> 6
//
// 1:1: 2:3, 3:6, 2:8, 1:9 1:10
//
// for case 0..11 -> 6
//
// 1:1: 2:3, 3:6, 2:8, 2:10 1:11
//
// for case 0..12 -> 6
//
// 1:1: 2:3, 3:6, 3:9, 2:11 1:12
//
// for case 0..13 -> 7
//
// 1:1: 2:3, 3:6, 3:9, 2:11 1:12, 1:13
//
// for case 0..14 -> 7
//
// 1:1: 2:3, 3:6, 3:9, 2:11 2:13 1: 14
//
// for case 15 -> 7
//
// 1:1: 2:3, 3:6, 3:9, 3:12 2:14 1:15
//
// for case 16 -> 7
//
// 1:1: 2:3, 3:6, 4:10, 3:13 2:15 1:16
//
// for case 17 -> 7
//
// 1:1: 2:3, 3:6, 4:10, 3:13 2:15 1:16 1:17
