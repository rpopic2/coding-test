#include <bitset>
#include <stdio.h>
#include <stdint.h>

using u32 = uint32_t;

constexpr int BUF_SIZE = 0x2000;
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

constexpr int SIZE = 100'0000;

int main() {
    std::bitset<SIZE> map;

    int n = get_int();

    for (int i = 0; i < n; ++i) {
        int a = get_int();
        map[a] = true;
    }

    int x = get_int();

    int answer = 0;
    for (int i = 1; i < (x + 1) / 2; ++i) {
        int index = x - i;
        if (index < SIZE && map[i] && map[index]) {
            ++answer;
        }
    }
    std::printf("%d\n", answer);
}

