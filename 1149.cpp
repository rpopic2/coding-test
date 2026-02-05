#include <iostream>
#include <vector>

#define range_in(name, end) for (int name = 0; name < end; ++name)

unsigned get_uint(std::istream &src) {
    unsigned u;
    src >> u;
    return u;
}

enum color {
    NONE, R, G, B
};

int main() {
    auto n = get_uint(std::cin);

    color last_color = NONE;
    range_in (i, n) {
        range_in (j, 3) {
            auto r = get_uint(std::cin);
            auto g = get_uint(std::cin);
            auto b = get_uint(std::cin);
        }
    }
}

