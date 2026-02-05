#pragma GCC optimize("O2")
#pragma GCC target("arch=haswell")

#include <unistd.h>

typedef unsigned char u8;
typedef unsigned u32;
typedef unsigned long long u64;

// #define unlikely(x) __builtin_expect(!!(x), 0)
#define unlikely(x) (x)

#define SRC_SIZE 1 << 12
#define SINK_SIZE 10

struct io {
    char *buf;
    u64 cur, end;
};

// in

// void read_all(struct io *io) {
//     io->cur = 0;
//     io->end = (u64)read(0, io->buf, SRC_SIZE);
// }

__attribute__((always_inline))
char get_c(struct io *io) {
    if (unlikely(io->cur == io->end)) {
        io->cur = 0;
        io->end = (u64)read(0, io->buf, SRC_SIZE);
    }
    return io->buf[io->cur++];
}

unsigned get_uint(struct io *io) {
    unsigned ret = 0;

    char current = get_c(io);

    while (current >= '0') {
        ret = ret * 10 + current - '0';
        current = get_c(io);
    }

    return ret;
}

// int get_int(struct io *io) {
//     int ret = 0;
//     u8 minus = 0;
//
//     char current = get_c(io);
//     if (current == '-') {
//         minus = 1;
//         current = get_c(io);
//     }
//
//     while (current >= '0') {
//         ret = ret * 10 + current - '0';
//         current = get_c(io);
//     }
//     if (minus) {
//         return -ret;
//     }
//
//     return ret;
// }

// out

// inline static void try_flush(struct io *io, u64 size);

// void put_c(struct io *io, char c) {
//     // try_flush(io, 1);
//     io->buf[io->cur++] = c;
// }

void put_uint(struct io *io, unsigned num) {
    u64 digits = 1;
    for (unsigned j = num; j >= 10; j /= 10)
        ++digits;
    // try_flush(io, digits);
    for (u64 j = digits; j--; num /= 10)
        io->buf[j + io->cur] = num % 10 + '0';
    io->cur += digits;
}

// void put_uint2(struct io *io, unsigned left) {
//     wp = wbuf + 10;
//     do {
//         *--wp = (char)(left % 10 | '0');
//         left /= 10;
//     } while (left);
// }

// void put_int(struct io *io, int num) {
//     if (num < 0) {
//         put_c(io, '-');
//         num = -num;
//     }
//     put_uint(io, (unsigned)num);
// }

// int main(void) {
int __libc_start_main(void) {
    char srcbuf[SRC_SIZE];
    char sinkbuf[SINK_SIZE];

    struct io *src = &(struct io){.buf = srcbuf};
    struct io *sink = &(struct io){.buf = sinkbuf};
    // sink->end = SINK_SIZE;
    // read_all(src);
    u32 k = get_uint(src), n = get_uint(src);

    u32 cable[10000];

    for (int i = 0; i < k; i++) {
        cable[i] = get_uint(src);
    }
    int right = 1 << 31;
    int left = 1;
    int mid;
    while (right - left >= 2) {
        mid = left + (right - left) / 2;
        int count = 0;
        for (int i = 0; i < k; i++) {
            count += cable[i] / mid;
        }
        if (count >= n) {
            left = mid;
        } else {
            right = mid;
        }
    }
    // put_uint(sink, left);
    char *wp = sinkbuf + 10;
    do {
        *--wp = (char)(left % 10 | '0');
        left /= 10;
    } while (left);
    write(1, wp, sinkbuf + 10 - wp);

    write(1, sinkbuf, sink->cur);
    _exit(0);
}
int main;

// inline static void try_flush(struct io *io, u64 size) {
//     if (unlikely(io->cur + size == SINK_SIZE)) {
//         write(1, io->buf, io->cur);
//         io->cur = 0;
//     }
// }
//
