#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    auto print_stars = [&N](int i) {
        string stars(1 + i * 2, '*');
        cout << string(N - i - 1, ' ');
        cout << stars;
        cout << '\n';
    };

    for (int i = 0; i < N; ++i) {
        print_stars(i);
    }
    for (int i = N - 2; i >= 0; --i) {
        print_stars(i);
    }
}
