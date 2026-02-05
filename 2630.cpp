#include <iostream>
#include <vector>
#include <bitset>
#include <cstdint>

using u32 = uint32_t;

struct slice {
    u32 ibegin;
    u32 jbegin;
    u32 iend;
    u32 jend;

    u32 imiddle();
    u32 jmiddle();
};

u32 slice::imiddle() {
    return (this->iend + this->ibegin) / 2;
}
u32 slice::jmiddle() {
    return (this->jend + this->jbegin) / 2;
}

using paper_t = std::vector<std::bitset<128>>;

paper_t paper;
int colors[2];

void recurse(slice s) {
    // std::cout << "recurse\n";
    bool color = paper[s.ibegin][s.jbegin];
    for (int i = s.ibegin; i < s.iend; ++i) {
        for (int j = s.jbegin; j < s.jend; ++j) {
            if (paper[i][j] != color) {
                goto outer_break;
            }
        }
    }
    colors[color] += 1;
    return;

outer_break:
    recurse({s.ibegin, s.jbegin, s.imiddle(), s.jmiddle()});
    recurse({s.imiddle(), s.jbegin, s.iend, s.jmiddle()});
    recurse({s.ibegin, s.jmiddle(), s.imiddle(), s.jend});
    recurse({s.imiddle(), s.jmiddle(), s.iend, s.jend});
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    u32 n;
    std::cin >> n;

    paper = paper_t(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool b;
            std::cin >> b;
            paper[i][j] = b;
        }
    }
    recurse({.ibegin = 0, .jbegin = 0, .iend = n, .jend = n});

    std::cout << colors[0] << '\n' << colors[1];
}

