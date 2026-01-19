#include <cstdio>

using uint = unsigned;
using ushort = unsigned short;
using uchar = unsigned char;

    uint stack[1 << 20];
int main() {
    uint n;
    std::scanf("%u", &n);

    uint *cur = stack;

    while (n--) {
        char command;
        std::scanf("%c", &command);

        if (command == '1') {
            uint x;
            std::scanf("%u", &x);
            *cur++ = x;
        } else if (command == '2') {
            if (cur != stack) {
                std::printf("%u\n", *--cur);
            } else {
                std::puts("-1");
            }
        } else if (command == '3') {
            std::printf("%zd\n", cur - stack);
        } else if (command == '4') {
            std::printf("%d\n", cur == stack);
        } else if (command == '5') {
            if (cur != stack) {
                std::printf("%d\n", cur[-1]);
            } else {
                std::puts("-1");
            }
        } // else unreachable
    }
}

