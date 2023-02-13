#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

constexpr char ws = ' ';

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    cin >> N;

    map<int, int> cards;
    int _index;
    for (int i = 0; i < N; ++i) {
        cin >> _index;
        cards[_index] += 1;

    }

    int M;
    cin >> M;
    int card_to_cnt;
    for (int i = 0; i < M; ++i) {
        cin >> card_to_cnt;
        cout << cards[card_to_cnt] << ::ws;
    }
}
