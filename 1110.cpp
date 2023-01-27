#include <iostream>
using namespace std;

int next_cycle(int n) {
    int sum = n / 10 + n % 10;
    return n % 10 * 10 + sum % 10;
}
int main() {
    int N;
    cin >> N;
    int last_cycle = N;
    int counter = 0;
    do {
        last_cycle = next_cycle(last_cycle);
        ++counter;
    } while (last_cycle != N);
    cout << counter;
}
