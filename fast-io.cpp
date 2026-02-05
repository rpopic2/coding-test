#include <stdint.h>
#include <stdio.h>

using u32 = uint32_t;
constexpr int BUF_SIZE = 1 << 16;
char buf[BUF_SIZE];
u32 cur, end;

char getc() {
    if (cur == end) {
        cur = 0;
        end = fread(buf, sizeof (char), BUF_SIZE, stdin);
        if (!end)
            return 0;
    }
    return buf[cur++];
}

int get_int() {
    int ret = 0;

    char current = getc();

    while (current <= ' ') {
        getc();
    }
    while (current >= '0') {
        ret = ret * 10 + current - '0';
        current = getc();
    }

    return ret;
}

