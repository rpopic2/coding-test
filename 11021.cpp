#include <iostream>
using namespace std;
int main() {
    int tc_count;
    cin >> tc_count;
    for (int a, b, i = 0; i < tc_count; ++i) {
        cin >> a >> b;
        cout << "Case #" << i + 1 << ": " << (a + b)<< endl;
    }
}
