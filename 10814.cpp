#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct member {
    int age;
    string name;
};
bool comp(const member &lhs, const member &rhs) {
    if (lhs.age < rhs.age) return true;
    else return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<member> vec;
    vec.resize(N);
    for (int i = 0; i < N; ++i) {
        int age; string name;
        cin >> age >> name;
        member m{age, name};
        vec[i] = m;
    }
    sort(vec.begin(), vec.end(), comp);
    for (const auto &m : vec) {
        cout << m.age << ' ' << m.name << '\n';
    }
}
