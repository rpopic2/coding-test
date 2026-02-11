#pragma GCC optimize("O2")
#pragma GCC target("arch=haswell")

#include <unistd.h>
#include <stdalign.h>

typedef unsigned char u8;
typedef unsigned u32;
typedef unsigned long long u64;

// #define unlikely(x) (x)
#define unlikely(x) __builtin_expect(!!(x), 0)
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
        io->cur = 0;
        io->end = (u64)read(STDIN_FILENO, io->buf, SRC_SIZE);
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
void flush(struct io *io);
forceinline
void try_flush(struct io *io, u64 size);

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

#define range_in(name, end) for (int name = 0; name < (end); ++name)


alignas(64) u8 srcbuf[SRC_SIZE];
alignas(64) u8 sinkbuf[SINK_SIZE];
alignas(64) unsigned dp[1025][1025];

int main(void) {}
// int main(void) {
int __libc_start_main(void) {

    struct io *src = &(struct io){.buf = srcbuf};
    struct io *sink = &(struct io){.buf = sinkbuf};

    unsigned n = get_uint(src), m = get_uint(src);

    for (unsigned i = 1; i <= n; ++i) {
        for (unsigned j = 1; j <= n; ++j) {
            unsigned val = get_uint(src);
            dp[i][j] = val + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    for (int i = 0; i < m; ++i) {
        unsigned x1 = get_uint(src),
                 y1 = get_uint(src),
                 x2 = get_uint(src),
                 y2 = get_uint(src);

        unsigned acc = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
        put_uint(sink, acc);
        put_c(sink, '\n');
    }

    flush(sink);
    _exit(0);
}

forceinline
void try_flush(struct io *io, u64 size) {
    if (unlikely(io->cur + size == SINK_SIZE)) {
        write(STDOUT_FILENO, io->buf, io->cur);
        io->cur = 0;
    }
}

forceinline
void flush(struct io *io) {
    write(STDOUT_FILENO, io->buf, io->cur);
}

