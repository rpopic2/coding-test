#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;


    vector<int> people;
    people.reserve(N);
    for (int i = 1; i <= N; ++i) {
        people.push_back(i);
    }

    vector<int> yosepus;
    yosepus.reserve(N);

    auto iter = people.begin();

    auto advance = [&iter, &people] {
        if (++iter == people.end()) {
            iter = people.begin();
        }
    };

    while (people.size() != 0) {
        for (int i = 0; i < K - 1; ++i) {
            advance();
        }
        yosepus.push_back(*iter);
        iter = people.erase(iter);
        if (iter == people.end()) {
            iter = people.begin();
        }
    }
    
    cout << '<';
    for (int i = 0; i < N - 1; ++i) {
        cout << yosepus[i] << ", ";
    }
    cout << yosepus[N - 1];
    cout << ">\n";
}
