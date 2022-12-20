#include <iostream>
constexpr char POPEN = '(', PCLOSE = ')';

int main()
{
    int paren_to_resolve = 0;
    char c;
    std::string buf;

    std::cin.ignore(1 << 16, '\n');
    while (std::cin.get(c))
    {
        if (c == POPEN) ++paren_to_resolve;
        else if (c == PCLOSE) --paren_to_resolve;
        if (c == '\n')
        {
            buf += paren_to_resolve == 0 ? "YES\n" : "NO\n";
            paren_to_resolve = 0;
        }
        if (paren_to_resolve < 0)
        {
            std::cin.ignore(1 << 16, '\n');
            buf += "NO\n";
            paren_to_resolve = 0;
        }
    }
    std::cout << buf;
}
