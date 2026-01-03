#include <iostream>
#include <vector>
#include <stack>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    while (true) {
        std::string s;
        std::getline(std::cin, s);
        if (!std::cin)
            break;
        if (s == ".") {
            return 0;
        }

        std::stack<char> stack;

        bool balanced = true;
        for (const char c : s) {
            if (c == '(' || c == '[') {
                stack.push(c);
            } else if ( c == ')' || c == ']') {
                if (stack.empty()) {
                    balanced = false;
                    break;
                }
                char top = stack.top();
                if (c == ')' && top != '(') {
                    balanced = false;
                    break;
                }
                if (c == ']' && top != '[') {
                    balanced = false;
                    break;
                }
                stack.pop();
            }
        }

        if (!stack.empty())
            balanced = false;

        std::cout << (balanced ? "yes\n" : "no\n");
    }
}

