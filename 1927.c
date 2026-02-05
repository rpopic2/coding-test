#pragma GCC optimize("O2")
#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef unsigned u32;
typedef unsigned long long u64;
#define BUF_SIZE 1 << 12
#define OBUF_SIZE 1 << 18
char *buf, *q;
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

u32 get_uint() {
    u32 ret = 0;

    char current = get_c();

    while (current >= '0') {
        ret = ret * 10 + current - '0';
        current = get_c();
    }

    return ret;
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

void put_c(char c) {
    *q++ = c;
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
void put_uint(u32 num) {
    int digits = 1;
    for (int j = num; j >= 10; j /= 10)
        ++digits;
    for (int j = digits; j--; num /= 10)
        q[j] = num % 10 + '0';
    q += digits;
}

// int __libc_start_main() {
int main() {
    char _buf[BUF_SIZE];
    buf = _buf;

    // char obuf[OBUF_SIZE];
    // q = obuf;

    u32 n = get_uint();

    u32 pq[100001], *p = pq;
    for (int i = 0; i < n; ++i) {
        u32 x = get_uint();

        if (x == 0) {
            if (p == pq) {
                printf("%d\n", 0);
                // put_c('\n');
                continue;
            }
            // printf("pop %d\n", *p);
            printf("%d\n", *--p);
            // put_uint(*--p);
            // put_c('\n');
            continue;
        }

        u32 *l = pq, *r = p;
        while (l < r) {
            u32 *m = l + ((r - l) / 2);
            if (*m > x)
                l = m + 1;
            else
                r = m;
        }
        memmove(l + 1, l, sizeof (u32) * (p++ - l));
        *l = x;
        // printf("push: %d\n", x);
        for (u32 *j = pq; j != p; ++j) {
            // printf("%zd: %d, ", j - pq, *j);
        }
        // printf("\n");
    }

    // syscall(1, 1, obuf, q - obuf);
    // write(1, obuf, q - obuf);
    fflush(stdout);
    _exit(0);
}
// int main;

