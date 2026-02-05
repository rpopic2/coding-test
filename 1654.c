#pragma GCC optimize("O2")
#include <unistd.h>

typedef unsigned u32;
typedef unsigned long long u64;
#define BUF_SIZE 1 << 15
#define OBUF_SIZE 1 << 9
char *buf;
u32 cur, end;

char get_c() {
    if (cur == end) {
        cur = 0;
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

char *q;
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
void put_uint(int num) {
    int digits = 1;
    for (int j = num; j >= 10; j /= 10)
        ++digits;
    for (int j = digits; j--; num /= 10)
        q[j] = num % 10 + '0';
    q += digits;
}

int __libc_start_main() {
    char _buf[BUF_SIZE];
    buf = _buf;

    char obuf[OBUF_SIZE];
    q = obuf;

    u32 k = get_uint(), n = get_uint();

    u32 max = 0;
    u32 lines[10000];
    for (u32 i = 0; i < k; ++i) {
        lines[i] = get_uint();
        max = lines[i] > max ? lines[i] : max;
    }

    u32 begin = 0, end = max;
    u32 candidate = 0;
    u32 last_cur = -1;
    while (1) {
        u32 cur = (end + begin) / 2;
        if (cur == begin)
            cur += 1;
        if (last_cur == cur)
            break;
        last_cur = cur;
        if (cur == candidate) {
            break;
        }
        u64 acc = 0;
        for (int i = 0; i < k; ++i) {
            u32 l = lines[i];
            acc += l / cur;
        }
        if (acc >= n) {
            if (cur > candidate) {
                candidate = cur;
            }
            begin = cur;
        } else {
            end = cur;
        }
    }
    put_uint(candidate);

    write(1, obuf, q - obuf);
    _exit(0);
}
int main;
