#include <iostream>
#include <list>
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

    auto pep_iter = people.begin();

    while (people.size() != 0) {
        if (++pep_iter == people.end()) {
            pep_iter = people.begin();
        }
        if (++pep_iter == people.end()) {
            pep_iter = people.begin();
        }
        yosepus.push_back(*pep_iter);
        pep_iter = people.erase(pep_iter);
        if (pep_iter == people.end()) {
            pep_iter = people.begin();
        }
    }
    
    cout << '<';
    for (int i = 0; i < N - 1; ++i) {
        cout << yosepus[i] << ", ";
    }
    cout << yosepus[N - 1] << '>' << '\n';
}
