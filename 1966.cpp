#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

struct document {
    int index;
    int priority;
};

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_count;
    std::cin >> testcase_count;

    for (int i = 0; i < testcase_count; ++i) {
        int n, m;
        std::cin >> n >> m;

        std::vector<document> queue(n);
        for (int j = 0; j < n; ++j) {
            std::cin >> queue[j].priority;
            queue[j].index = j;
        }

        int print_count = 0;

        for (int j = 0; j < queue.size(); ++j) {
            document doc = queue[0];
            bool defer = false;
            for (int k = 1; k < queue.size(); ++k) {
                document doc_other = queue[k];
                if (doc_other.priority > doc.priority) {
                    defer = true;
                    break;
                }
            }
            queue.erase(std::next(queue.begin(), j));
            if (defer) {
                queue.push_back(doc);
            } else {
                print_count += 1;
                if (doc.index == m)
                    break;
            }
        }
        std::cout << print_count << '\n';
    }
}

