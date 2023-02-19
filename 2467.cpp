#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // read input
    int N;
    cin >> N;

    vector<int> liquids(N);
    for (int i = 0; i < N; ++i) {
        cin >> liquids[i];
    }

    int best_sum = numeric_limits<int>::max();
    pair<int, int> best_pair;
    auto start = liquids.begin();

    // 매 용액마다
    for (const auto &liq : liquids) {

        // 이분 탐색해서 현재 용액보다 큰 용액 찾기
        auto simmilar = std::upper_bound(++start, liquids.end(), liq * -1);

        // 가장 합이 0에 가까운 용액이 있다면 업데이트
        auto update = [&]() {
            //check for validity
            if (simmilar == liquids.end()) return;

            int sum = *simmilar + liq;
            sum = ::abs(sum);

            if (sum < best_sum) {
                best_sum = sum;
                best_pair = {liq, *simmilar};
            }
        };

        // 현재 용액에 업데이트
        update();

        // 
        if (simmilar == start) continue;
        // 현재 용액 이전도 확인. 
        --simmilar;
        update();

        // 양수 용액이면 더 이상 탐색할 필요가 없음. 양수만 있으면 맨 왼쪽 둘이 정답.
        if (liq > 0) break;
    }

    // 0에 가장 가까운 용액 출력
    auto [l, r] = best_pair;
    cout << l << ' ' << r << '\n';
}
