#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int tc_count;
    cin >> tc_count;
    for (int i = 0; i < tc_count; ++i) {
        int a, b;
        cin >> a >> b;
        printf("Case #%d: %d + %d = %d\n", i, a, b, a+b);
    }
}
