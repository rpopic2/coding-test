#include <iostream>
constexpr int BIG_NUM = 1 << 16;

void cnt_parens(std::string &buf)
{
    if (std::cin.peek() == EOF) return;
    int paren_to_resolve = 0;
    char c;
    while (std::cin.get(c))
    {
        if (c == '(') ++paren_to_resolve;
        else if (c == ')') --paren_to_resolve;
        if (c == '\n' || paren_to_resolve < 0) break;
    }
    buf += paren_to_resolve == 0 ? "YES\n" : "NO\n";
    if (c != '\n') std::cin.ignore(BIG_NUM, '\n');
}

int main()
{
    std::string buf = "";
    std::cin.ignore(1 << 16, '\n');
    while (!std::cin.eof()) cnt_parens(buf);
    std::cout << buf;
}
