#include <algorithm>
#include <string>
#include <vector>

int solution(int n, int k, std::vector<int> enemy) {
    std::vector<int> buffer;
    buffer.reserve(enemy.size());
    std::make_heap(buffer.begin(), buffer.end());

    int answer = 0;
    int sum = 0;

    for (const auto i : enemy) {
        buffer.push_back(i);
        std::push_heap(buffer.begin(), buffer.end());
        sum += i;

        if (sum <= n) {
            ++answer;
        } else if (k > 0) {
            std::pop_heap(buffer.begin(), buffer.end());
            sum -= buffer.back();
            buffer.pop_back();
            --k;
            ++answer;
        } else {
            break;
        }
    }

    return answer;
}

