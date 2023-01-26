#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b;
    char dummy;
    for (int i = 0; i < n; ++i) {
        cin >> a >> dummy >> b;
        cout << a + b << '\n';
    }
}

