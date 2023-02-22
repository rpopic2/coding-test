#include <iostream>
#include <vector>
using namespace std;
using matrix = vector<vector<char>>;

constexpr int TARGET = 8;
constexpr char W = 'W';
constexpr char B = 'B';

int main() {
    int N, M;
    cin >> N >> M;

    matrix board(N, vector<char>(M, 0));
    for (auto &v : board) {
        for (auto &w : v) {
            cin >> w;
        }
    }

    for (const auto &
}
