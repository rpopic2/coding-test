//Time complexity of std::find is O(n), where n is number of elements
//Time complexity of std::set::find is O(log n), where n is number of elements
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    set<int> A;
    for (int c, i = 0; i < N; ++i) {
        cin >> c;
        A.insert(c);
    }

    int M;
    cin >> M;
    for (int c, i = 0; i < M; ++i) {
        cin >> c;
        auto query = A.find(c);
        if (query == A.end()) cout << 0;
        else cout << 1;
        cout << '\n';
    }
}
