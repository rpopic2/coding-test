#include <iostream>
#include <vector>
#include <array>
#include <queue>
using namespace std;
using vertex = pair<int, int>;
using matrix = vector<vector<int>>;

constexpr array<vertex, 4> directions = {
    pair<int, int>{1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

int N;
matrix map;

bool is_valid(vertex v) {
    auto x = v.first;
    auto y = v.second;
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    if (map[x][y] == 0) return false;
    return true;
}

vector<vertex> bfs_search_at(vertex vert) {
    vector<vertex> isle;
    queue<vertex> q;
    q.push(vert);
    while (!q.empty()) {
        auto pair = q.front();
        auto x = pair.first;
        auto y = pair.second;
        q.pop();
        isle.push_back(pair);
    }
    return isle;
}

void scan_map() {
    for (const auto &col : map) {
        for (const auto &node : col) {
            if (node == 0) continue;
            
        }
    }
}

int main() {
    cin >> N;
    //generate map from input
    map = matrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }
}
