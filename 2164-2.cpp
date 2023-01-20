#include <iostream>
#include <list>
using namespace std;

int main() {
    int N;
    cin >> N;
    list<int> ls;
    for (int i = N; i >= 0; --i) {
        ls.push_back(i + 1);
    }
    for (;;) {
        ls.pop_back();
        ls.push_front(ls.back());
        ls.pop_back();
        if (ls.size() == 1) break;
        cout << ls.size() << endl;
    }
    cout << ls.front();
}
