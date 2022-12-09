#include <iostream>

int main()
{
    std::string s = "HI!";
    std::cout << s[2]; // print !
    std::cout << s[3]; // print nothing
    std::cout << (s[3] == '\0');
    std::cout << (s[4] == '\0');
    std::cout << s.length();
}
