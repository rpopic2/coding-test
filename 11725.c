#pragma GCC optimize("O2")
#pragma GCC target("arch=haswell")
#include <unistd.h>

typedef unsigned char u8;
typedef unsigned u32;
typedef unsigned long long u64;
#define BUF_SIZE 1 << 17
#define OBUF_SIZE 1 << 17
char *buf, *q, *obuf, *obuf_end;
u32 cur, end;

char get_c() {
    if (cur == end) {
        cur = 0;
        // end = syscall(0, 0, buf, BUF_SIZE);
        end = read(0, buf, BUF_SIZE);
        if (!end)
            return 0;
    }
    return buf[cur++];
}
int get_uint() {
    int ret = 0;

    char current = get_c();

    while (current >= '0') {
        ret = ret * 10 + current - '0';
        current = get_c();
    }

    return ret;
}
int get_int() {
    int ret = 0;
    u8 minus = 0;

    char current = get_c();
    if (current == '-') {
        minus = 1;
        current = get_c();
    }

    while (current >= '0') {
        ret = ret * 10 + current - '0';
        current = get_c();
    }
    if (minus) {
        return -ret;
    }

    return ret;
}

void oflush() {
    write(1, obuf, q - obuf);
    q = obuf;
}
void put_c(char c) {
    if (q + 1 == obuf_end) {
        oflush();
    }
    *q++ = c;
}
void put_uint(int num) {
    int digits = 1;
    for (int j = num; j >= 10; j /= 10)
        ++digits;
    if (q + digits >= obuf_end) {
        oflush();
    }
    for (int j = digits; j--; num /= 10)
        q[j] = num % 10 + '0';
    q += digits;
}
void put_int(int num) {
    if (num < 0) {
        *q++ = '-';
        num = -num;
    }
    put_uint(num);
}


int __libc_start_main() {
    char _buf[BUF_SIZE];
    buf = _buf;

    char _obuf[OBUF_SIZE];
    obuf = _obuf;
    q = obuf;



    // syscall(1, 1, obuf, q - obuf);
    write(1, obuf, q - obuf);
    _exit(0);
}
int main;
