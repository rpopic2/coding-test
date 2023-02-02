#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    while (cin >> s) {
        if (s == "0") break;
        int strmid = s.length() / 2;
        auto front = s.substr(0, strmid);
        reverse(s.begin(), s.end());
        auto back = s.substr(0, strmid);
        if (front == back) {
            cout << "yes\n";
        }
        else cout << "no\n";
    }
}
