#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(2);
    std::vector<int> vec2;
    vec2 = vec;
    std::cout << vec2[0];
}
