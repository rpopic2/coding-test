#pragma GCC optimize("O2")
// #include <unistd.h>
// #include <stdio.h>

typedef unsigned u32;
#define BUF_SIZE 1 << 14
#define OBUF_SIZE 10

char *buf;
u32 cur, end;
char *obuf, *q;

char peek() {
    if (cur == end) {
        cur = 0;
        end = syscall(0, 0, buf, BUF_SIZE);
        if (!end)
            return 0;
    }
    return buf[cur];
}

char get_c() {
    peek();
    return buf[cur++];
}


int get_int() {
    int ret = 0;
    char minus = 0;

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

void put_int(int num) {
    if (num < 0) {
        *q++ = '-';
        num = -num;
    }
    int digits = 1;
    for (int j = num; j >= 10; j /= 10)
        ++digits;
    for (int j = digits; j--; num /= 10)
        q[j] = num % 10 + '0';
    q += digits;
}

// int main() {
int __libc_start_main() {
    char buf_[BUF_SIZE];
    char obuf_[OBUF_SIZE];
    buf = buf_;
    obuf = obuf_;
    q = obuf;
    int n = get_int();

    int acc = 0;
    int minus_best = -100000;
    int best = 0;
    char only_minus = 1;
    for (int i = 0; i < n; ++i) {
        int x = get_int();
        acc += x;
        if (x < 0) {
            minus_best = minus_best > x ? minus_best : x;
        } else {
            only_minus = 0;
        }
        if (acc < 0) {
            acc = 0;
        }
        best = acc > best ? acc : best;
    }
    if (only_minus) {
        put_int(minus_best);
    } else {
        put_int(best);
    }

    syscall(1, 1, obuf, q - obuf);
    _exit(0);
}
int main;



