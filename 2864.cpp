#include <cstdlib>
#include <iostream>
#include <string>

void replace_all(std::string &out_s, char to_replace, char replace_with) {
    for (auto &c : out_s) {
        if (c == to_replace) {
            c = replace_with;
        }
    }
}

int main()
{
    std::string a, b;
    std::cin >> a >> b;

    replace_all(a, '5', '6');
    replace_all(b, '5', '6');

    auto max = std::stoi(a) + std::stoi(b);

    replace_all(a, '6', '5');
    replace_all(b, '6', '5');

    auto min = std::stoi(a) + std::stoi(b);

    std::cout << min << ' ' << max;
}
