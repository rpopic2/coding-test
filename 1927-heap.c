#pragma GCC optimize("O2")
#include <unistd.h>
// #include <string.h>
// #include <stdio.h>

typedef unsigned u32;
typedef unsigned long long u64;
#define BUF_SIZE 1 << 13
#define OBUF_SIZE 1 << 12
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
void put_int(int num) {
    if (num < 0) {
        put_c('-');
        num = -num;
    }
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
void put_uint(u32 num) {
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
inline static void swap(u32 *a, u32 *b) {
    u32 tmp = *a;
    *a = *b;
    *b = tmp;
}

int __libc_start_main() {
// int main() {
    char _buf[BUF_SIZE];
    buf = _buf;

    char _obuf[OBUF_SIZE];
    u32 pq[100001], *p = pq;
    obuf = _obuf;
    obuf_end = obuf + sizeof _obuf;
    q = obuf;

    u32 n = get_uint();

    for (int i = 0; i < n; ++i) {
        u32 x = get_uint();

        if (x == 0) {
            if (p == pq) {
                put_c('0'), put_c('\n');
                // printf("%d\n", 0);
                continue;
            }
            // printf("pop %d\n", *p);
            u32 pop = *pq;
            put_uint(pop), put_c('\n');
            // printf("%d\n", pop);
            *pq = *--p;

            u32 *self = pq;
            u32 *rchild = pq + ((self - pq) * 2) + 2;
            u32 *lchild = rchild - 1;

            // size_t size = p - pq;
            //
            // while (1) {
            //     size_t i = self - pq;
            //     size_t l = 2*i + 1;
            //     size_t r = 2*i + 2;
            //
            //     if (l >= size) break;  // no children
            //
            //     size_t max_child = l;
            //     if (r < size && pq[r] > pq[l])
            //         max_child = r;
            //
            //     if (pq[i] >= pq[max_child]) break;
            //
            //     swap(&pq[i], &pq[max_child]);
            //     self = &pq[max_child];
            // }
            while (self < p) {
                if (lchild >= p) break;
                if (*self <= *rchild && *self <= *lchild)
                    break;
                if (*rchild < *lchild) {
                    swap(self, rchild);
                    self = rchild;
                } else {
                    swap(self, lchild);
                    self = lchild;
                }
                rchild = pq + ((self - pq) * 2) + 2;
                lchild = rchild - 1;
            }

#if DBG
            printf("pop: %d\n", pop);
            for (u32 *j = pq; j != p; ++j) {
                printf("%zd: %d, ", j - pq, *j);
            }
            printf("\n");
#endif

            // put_uint(*--p);
            // put_c('\n');
            continue;
        }

        int index = p - pq;
        *p++ = x;

        u32 *self = pq + index;
        u32 *parent = pq + (index - 1) / 2;
        while (parent - pq >= 0) {
            if (x >= *parent)
                break;
            swap(self, parent);
            self = parent;
            parent = pq + (self - pq - 1) / 2;
        }

#if DBG
        printf("push: %d\n", x);
        for (u32 *j = pq; j != p; ++j) {
            printf("%zd: %d, ", j - pq, *j);
        }
        printf("\n");
#endif
    }

    // syscall(1, 1, obuf, q - obuf);
    write(1, obuf, q - obuf);
    // fflush(stdout);
    _exit(0);
}
int main;

