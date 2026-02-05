#include <stdbool.h>
#pragma GCC optimize("O2")
#pragma GCC target("arch=haswell")

#include <unistd.h>
#include <stdalign.h>

typedef unsigned char u8;
typedef unsigned u32;
typedef unsigned long long u64;

#define unlikely(x) __builtin_expect(!!(x), 0)
#define forceinline __attribute__((always_inline))

#define range(name, end) for (int name = 0; name < end; ++name)

#define SRC_SIZE 1 << 10
#define SINK_SIZE 1 << 6

struct io {
    char *buf;
    u64 cur, end;
};

// in

forceinline
char get_c(struct io *io) {
    if (unlikely(io->cur == io->end)) {
        io->cur = 0;
        io->end = (u64)read(0, io->buf, SRC_SIZE);
        if (!io->end)
            return 0;
    }
    return io->buf[io->cur++];
}

unsigned get_uint(struct io *io) {
    unsigned ret = 0;

    char current = get_c(io);

    while (current >= '0') {
        ret = ret * 10 + (u8)current - '0';
        current = get_c(io);
    }

    return ret;
}

int get_int(struct io *io) {
    int ret = 0;
    u8 minus = 0;

    char current = get_c(io);
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

inline static void flush(struct io *io);
inline static void try_flush(struct io *io, u64 size);

void put_c(struct io *io, char c) {
    try_flush(io, 1);
    io->buf[io->cur++] = c;
}

void put_uint(struct io *io, unsigned num) {
    u64 digits = 1;
    for (unsigned j = num; j >= 10; j /= 10)
        ++digits;
    try_flush(io, digits);
    for (u64 j = digits; j--; num /= 10)
        io->buf[j + io->cur] = (char)(num % 10) + '0';
    io->cur += digits;
}

void put_int(struct io *io, int num) {
    if (num < 0) {
        put_c(io, '-');
        num = -num;
    }
    put_uint(io, (unsigned)num);
}



typedef struct line {
    __uint128_t data;
} line_t;

u8 line_at(line_t this, int index) {
    return this.data >> index & 1;
}

typedef struct slice {
    u32 ibegin;
    u32 jbegin;
    u32 iend;
    u32 jend;
} slice;

u32 imiddle(const slice *this) {
    return (this->iend + this->ibegin) / 2;
}
u32 jmiddle(const slice *this) {
    return (this->jend + this->jbegin) / 2;
}

int colors[2];
line_t *paper;

void recurse(slice s) {
    // std::cout << "recurse\n";
    bool color = line_at(paper[s.ibegin], s.jbegin);
    for (int i = s.ibegin; i < s.iend; ++i) {
        for (int j = s.jbegin; j < s.jend; ++j) {
            if (line_at(paper[i], j) != color) {
                goto outer_break;
            }
        }
    }
    colors[color] += 1;
    return;

outer_break:
    recurse((slice){s.ibegin, s.jbegin, imiddle(&s), jmiddle(&s)});
    recurse((slice){imiddle(&s), s.jbegin, s.iend, jmiddle(&s)});
    recurse((slice){s.ibegin, jmiddle(&s), imiddle(&s), s.jend});
    recurse((slice){imiddle(&s), jmiddle(&s), s.iend, s.jend});
}

// int main(void) {
int __libc_start_main(void) {
    alignas(64) char srcbuf[SRC_SIZE];
    alignas(64) char sinkbuf[SINK_SIZE];

    struct io *src = &(struct io){.buf = srcbuf};
    struct io *sink = &(struct io){.buf = sinkbuf};

    u32 n = get_uint(src);

    alignas(64) line_t s_paper[128] = {0};
    paper = s_paper;

    range(i, n) {
        line_t *line = paper + i;
        range(j, n) {
            u32 color = get_uint(src);
            line->data |= (__uint128_t)color << j;
        }
    }
    recurse((slice){.ibegin = 0, .jbegin = 0, .iend = n, .jend = n});

    put_uint(sink, colors[0]);
    put_c(sink, '\n');
    put_uint(sink, colors[1]);
    write(1, sinkbuf, sink->cur);
    _exit(0);
}

int main(void) {}

inline static void try_flush(struct io *io, u64 size) {
    if (unlikely(io->cur + size == io->end)) {
        write(1, io->buf, SINK_SIZE);
        io->cur = 0;
    }
}

