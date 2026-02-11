#include <iostream>
#include <vector>

#define range_in(name, end) for (int name = 0; name < (end); ++name)

unsigned get_uint(std::istream &src) {
    unsigned u;
    src >> u;
    return u;
}

int main() {
    auto n = get_uint(std::cin);

    unsigned rbest = 0;
    unsigned gbest = 0;
    unsigned bbest = 0;

    range_in (i, n) {
        auto r = get_uint(std::cin);
        auto g = get_uint(std::cin);
        auto b = get_uint(std::cin);

        unsigned rtmp = r + std::min(gbest, bbest);
        unsigned gtmp = g + std::min(rbest, bbest);
        unsigned btmp = b + std::min(rbest, gbest);

        rbest = rtmp;
        gbest = gtmp;
        bbest = btmp;
    }

    std::cout << std::min({rbest, gbest, bbest});
}

