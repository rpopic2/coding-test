// see 10866.c for implementing deque from scratch
#include <iostream>
#include <deque>
using namespace std;
constexpr char newl = '\n';

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    cin >> N;

    deque<int> dq;
    string cmd;
    int arg;

    while (N--) {
        cin >> cmd;

        // handling cmds that needs to check whether dq is empty
        if (cmd == "pop_front" || cmd == "pop_back" || cmd == "front" || cmd == "back") {
            if (dq.empty()) {
                cout << "-1" << newl;
                continue;
            }
        }

        // handle cmds. can safely access elements, not worring about empty dq
        if (cmd == "push_front") {
            cin >> arg;
            dq.push_front(arg);
        } else if (cmd == "push_back") {
            cin >> arg;
            dq.push_back(arg);
        } else if (cmd == "pop_front") {
            auto front = dq.front();
            dq.pop_front();
            cout << front << newl;
        } else if (cmd == "pop_back") {
            auto back = dq.back();
            dq.pop_back();
            cout << back << newl;
        } else if (cmd == "empty") {
            int is_empty = dq.empty();
            cout << is_empty << newl;
        } else if (cmd == "size") {
            cout << dq.size() << newl;
        } else if (cmd == "front") {
            cout << dq.front() << newl;
        } else if (cmd == "back") {
            cout << dq.back() << newl;
        }
    }
}
