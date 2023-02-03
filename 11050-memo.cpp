#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> memo(11, vector<int>(11, -1));
int bi_coef(int n, int k) {
    if (k == 0 || n == k) return 1;
    auto &current_ref = memo[n][k];
    if (current_ref == -1) current_ref = bi_coef(n - 1, k - 1) + bi_coef(n - 1, k);
    return current_ref;
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << bi_coef(N, K) << '\n';
}
