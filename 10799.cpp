#include <iostream>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::string s;
    std::cin >> s;

    auto it = s.begin();
    int stack = 0;
    int answer = 0;
    while (it != s.end()) {
        if (*it == '(') {
            stack += 1;
        } else {
            stack -= 1;
            if (*std::prev(it, 1) == '(')
                answer += stack;
            else
                answer += 1;
        }
        ++it;
    }
    std::cout << answer << '\n';
}

