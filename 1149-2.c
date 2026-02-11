#define min(a, b) (a < b ? a : b)

#define ReadInt(n) { \
    char c = *p++; \
    for (; ~c & 16; c = *p++); \
    for (; c & 16; c = *p++) n = 10 * n + (c & 15); }

#define WriteInt(n) { \
    int m = n, sz = GetSize(m); \
    for (int j = sz; j --> 0; m /= 10) w[i + j] = m % 10 | 48; \
    i += sz; }

inline int GetSize(int n) {
    int ret = 1;
    for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
    return ret; }

#pragma GCC optimize("O2")
#pragma GCC target("arch=haswell")

#include <unistd.h>
#include <stdalign.h>

typedef unsigned char u8;
typedef unsigned u32;
typedef unsigned long long u64;

#define unlikely(x) 0
#define forceinline __attribute__((always_inline)) static inline
#define cold __attribute__((cold))

#define SRC_SIZE 1 << 16
#define SINK_SIZE 1 << 5

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
    u64 digits = 1;
    for (unsigned j = num; j >= 10; j /= 10)
        ++digits;
    try_flush(io, digits);
    for (u64 j = digits; j--; num /= 10)
        io->buf[j + io->cur] = (u8)(num % 10) + '0';
    io->cur += digits;
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

// int main(void) {
int __libc_start_main(void) {
    u8 srcbuf[SRC_SIZE];
    u8 sinkbuf[SINK_SIZE];
    u8 *p = srcbuf;

    struct io *src = &(struct io){.buf = srcbuf};
    struct io *sink = &(struct io){.buf = sinkbuf};

    drain(src);

    unsigned nu;
    ReadInt(nu);

    unsigned rbest = 0;
    unsigned gbest = 0;
    unsigned bbest = 0;

    range_in (i, nu) {
        unsigned r;
        unsigned g;
        unsigned b;
        ReadInt(r);
        ReadInt(g);
        ReadInt(b);

        unsigned rtmp = r + min(gbest, bbest);
        unsigned gtmp = g + min(rbest, bbest);
        unsigned btmp = b + min(rbest, gbest);

        rbest = rtmp;
        gbest = gtmp;
        bbest = btmp;
    }

    // put_uint(sink, );
    unsigned ans = min(min(rbest, gbest), bbest);
    u8 *w = sinkbuf;
    int i = 0;
    WriteInt(ans);

    flush(sink);
    _exit(0);
}

int main(void) {}

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
