#include <iostream>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    bool a = x * y > 0;
    bool b = x > 0;
    if (a && b) {
        cout << 1;
    } else if (a && !b) {
        cout << 3;
    } else if (!a && b) {
        cout << 4;
    } else {
        cout << 2;
    }
}
