#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

using u32 = uint32_t;
constexpr int BUF_SIZE = 50;
char buf[BUF_SIZE];
u32 cur, end;

char peek() {
    if (cur == end) {
        cur = 0;
        end = fread(buf, sizeof (char), BUF_SIZE, stdin);
        if (!end)
            return 0;
    }
    return buf[cur];
}

char getc() {
    peek();
    return buf[cur++];
}


int get_int() {
    int ret = 0;

    char current = getc();

    // while (current <= ' ') {
    //     getc();
    // }
    while (current >= '0') {
        ret = ret * 10 + current - '0';
        current = getc();
    }
    cur-=1;

    return ret;
}


int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    int acc = 0;
    char sign = '+';
    while (true) {
        if (!peek())
            break;
        int n = get_int();
        if (sign == '+') {
            acc += n;
        } else {
            int minus_acc = n;
            while (peek() == '+') {
                getc();
                n = get_int();
                minus_acc += n;
            }
            acc -= minus_acc;
        }
        // std::cout << "found " << i << std::endl;
        // printf("sign '%d'\n", cur);
        sign = getc();
    }
    printf("%d", acc);
    fflush(stdout);
    _Exit(0);
}

// -1-2-3-4-5
// all plus/minus-> just add
// 55-50+40
// 55-50-80
// 55-50+40-90+100-70

