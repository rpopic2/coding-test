#include <iostream>

int main() {
    std::string name(100, ' ');
    std::cin >> name;

    std::string result;
    result.reserve(100);

    result.push_back(name[0]);

    std::string::size_type tmp_result = 0;
    while (true) {
        tmp_result = name.find('-', tmp_result + 1);
        if (tmp_result == std::string::npos)
            break;

        result.push_back(name[tmp_result + 1]);
    }

    std::cout << result << '\n';
}
