#include <iostream>
#include <vector>
using namespace std;

int bi_coef(int n, int k) {
    return bi_coef(n - 1, k - 1) + bi_coef(n - 1, k);
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << bi_coef(N, K);
}
