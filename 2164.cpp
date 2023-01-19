#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    int result = 1;
    for (; result <= N; result <<= 1) {
    }
    cout << (result >> 1) << endl;
}
