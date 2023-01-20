#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    cout << (n - 1) + ((n - 1) * n);
}

// 3x3 example
// divide 3x3 into three parts -> requires 3 x 1 = 2 moves;
// 3x3 becomes three (3 x 1), 2 x 3 = 6 moves;
// total 8 moves.
// n x 1 requires n - 1 moves to solve.
// so the answer is : (n - 1) + (m - 1) * n
