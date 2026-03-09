#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> lines(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> lines[i];
    }
    std::reverse(lines.begin(), lines.end());

    std::vector<int> stack;
    int num = 1;
    while (true) {
        if (!stack.empty()) {
            int back = stack.back();
            if (back == num) {
                stack.pop_back();
                //std::cout <<" fgive"<< num;
                num += 1;
        // printf("\n%d %d\n", stack.size(), lines.size());
                continue;
            }
        }
        if (!lines.empty()) {
            int back = lines.back();
            lines.pop_back();
            if (back == num) {
                    //std::cout <<" give"<< num;
                num += 1;
                continue;
            }
            stack.push_back(back);
                //std::cout <<" stack"<< back;
            continue;
        }
        break;
    }
    if (stack.empty() && lines.empty()) {
        std::cout << "Nice\n";
    } else {
        std::cout << "Sad\n";
    }
}

