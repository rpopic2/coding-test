#include <iostream>
using namespace std;
constexpr char endl = '\n';

int main() { 
    cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        cout << string(i, ' ') << string(N - i, '*') << ::endl;
    }
}
