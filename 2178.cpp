#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
constexpr auto endl = '\n';

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> maze(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            auto c = cin.get();
            if (c == '\n') continue;
            maze[i][j] = c - '0';
        }
    }
}
