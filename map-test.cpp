#include <iostream>
#include <map>

int main() {
    std::map<int, int> m;
    ++m[1];
    std::cout << m[1];
}
