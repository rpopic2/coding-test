#pragma GCC optimize("O2")
#pragma GCC target("arch=haswell")

#include <unistd.h>

typedef unsigned char u8;
typedef unsigned u32;
typedef unsigned long long u64;

#define unlikely(x) __builtin_expect(!!(x), 0)
// #define unlikely(x) (x)
// #define unlikely(x) 0
#define forceinline __attribute__((always_inline)) static inline
#define cold __attribute__((cold))

#define SRC_SIZE 1 << 17
#define SINK_SIZE 1 << 17
#define UINT_SIZE 10

struct io {
    u8 *buf;
    u64 cur, end;
};

// in

forceinline
void drain(struct io *io) {
    io->cur = 0;
    io->end = (u64)read(STDIN_FILENO, io->buf, SRC_SIZE);
}

forceinline
u8 get_c(struct io *io) {
    if (unlikely(io->cur == io->end)) {
        drain(io);
    }
    return io->buf[io->cur++];
}

forceinline
unsigned get_uint(struct io *io) {
    unsigned ret = 0;

    u8 current = get_c(io);

    while (current >= '0') {
        ret = ret * 10 + (u8)current - '0';
        current = get_c(io);
    }

    return ret;
}

forceinline
int get_int(struct io *io) {
    int ret = 0;
    u8 minus = 0;

    u8 current = get_c(io);
    if (current == '-') {
        minus = 1;
        current = get_c(io);
    }

    while (current >= '0') {
        ret = ret * 10 + current - '0';
        current = get_c(io);
    }
    if (minus) {
        return -ret;
    }

    return ret;
}

// out

forceinline
void flush(struct io *io) {
    write(STDOUT_FILENO, io->buf, io->cur);
}

forceinline
void try_flush(struct io *io, u64 size) {
    if (unlikely(io->cur + size == SINK_SIZE)) {
        flush(io);
        io->cur = 0;
    }
}

forceinline
void put_c(struct io *io, u8 c) {
    try_flush(io, 1);
    io->buf[io->cur++] = c;
}

forceinline
void put_uint(struct io *io, unsigned num) {
    u8 tmp[UINT_SIZE];
    u64 j = 0;

    do tmp[j++] = num % 10 + '0';
    while (num /= 10);

    while (j--)
        put_c(io, tmp[j]);
}

forceinline
void put_int(struct io *io, int num) {
    if (num < 0) {
        put_c(io, '-');
        num = -num;
    }
    put_uint(io, (unsigned)num);
}

forceinline
void print_uint(unsigned num) {
    u8 tmp[UINT_SIZE], *p = tmp + UINT_SIZE;

    do *--p = num % 10 + '0';
    while (num /= 10);
    write(STDOUT_FILENO, p, (size_t)(tmp + UINT_SIZE - p));
}

int main(void) {}
// int main(void) {
int __libc_start_main(void) {
    _Alignas(64) u8 srcbuf[SRC_SIZE];
    _Alignas(64) u8 sinkbuf[SINK_SIZE];

    struct io *src = &(struct io){.buf = srcbuf};
    struct io *sink = &(struct io){.buf = sinkbuf};

    flush(sink);
    _exit(0);
}

