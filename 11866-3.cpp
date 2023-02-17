#include <iostream>
#include <queue>
using namespace std;

inline int pop(queue<int> q) {
    if (q.empty()) {
        return -1;
    }
    int tmp = q.front();
    q.pop();
    return tmp;
}

void pop_move(queue<int> from, queue<int> dest) {
    auto tmp = pop(from);
    if (tmp == -1) return;
    from.push(tmp);
}

int main() {
    int N, K;
    cin >> N >> K;

    // init queue
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }

    queue<int> yosepus;

    while (!q.empty()) {
        queue<int> tmp_q;
        pop_move(q, tmp_q);
        pop_move(q, tmp_q);

        cout << q.front() << endl;
        pop_move(q, yosepus);
        while (!q.empty()) {
            pop_move(q, tmp_q);
        }
        q = tmp_q;
    }

    cout << '<';
    for (int i = 0; i < N - 1; ++i) {
        cout << yosepus.front() << ", ";
        yosepus.pop();
    }
    cout << yosepus.front() << '>' << '\n';
}
