//10845.c 에 처음부터 큐를 구현한 코드가 있으니 그걸로 봐주세요!
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    queue<int> queue;

    std::string cmd;
    int arg = 0;
    int result = 0;
    for (int i = 0; i < N; ++i) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> arg;
            queue.push(arg);
            continue;
        } else if (cmd == "front") {
            if (queue.empty()) {
                result = -1;
            } else {
                result = queue.front();
            }
        } else if (cmd == "back") {
            if (queue.empty()) {
                result = -1;
            } else {
                result = queue.back();
            }
        } else if (cmd == "pop") {
            if (queue.empty()) {
                result = -1;
            } else {
                result = queue.front();
                queue.pop();
            }
        } else if (cmd == "size") {
            result = queue.size();
        } else if (cmd == "empty") {
            result = queue.empty();
        }
        cout << result << '\n';
    }
}
