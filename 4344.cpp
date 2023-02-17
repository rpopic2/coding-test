#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    int tc_count;
    cin >> tc_count;

    while (tc_count--) {
        int student_count;
        cin >> student_count;
        vector<int> scores(student_count);
        for (int i = 0; i < student_count; ++i) {
            cin >> scores[i];
        }
        auto sum = accumulate(scores.begin(), scores.end(), 0);
        float average = sum / static_cast<float>(student_count);
    }
}
