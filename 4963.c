#pragma GCC optimize("O2")
#pragma GCC target("arch=haswell")

#include <unistd.h>
#include <stdalign.h>

typedef unsigned char u8;
typedef unsigned u32;
typedef unsigned long long u64;

#define unlikely(x) __builtin_expect(!!(x), 0)
#define forceinline __attribute__((always_inline))
#define cold __attribute__((cold))

#define SRC_SIZE 1 << 13
#define SINK_SIZE 1 << 9

struct io {
    char *buf;
    u64 cur, end;
};

// in

// forceinline
char get_c(struct io *io) {
    if (unlikely(io->cur == io->end)) {
        io->cur = 0;
        io->end = (u64)read(STDIN_FILENO, io->buf, SRC_SIZE);
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

typedef int map_t[50][50];

typedef struct point {
    int x; int y;

} point;

point add(point lhs, point rhs) {
    return (point){ lhs.x + rhs.x, lhs.y + rhs.y };
}

map_t map;
int w, h;
point q[1 << 9], *qp = q;
int count;

const point directions[] = {
    {0, 1}, {0, -1}, {-1, 0}, {1, 0},
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};
const size_t directions_len = sizeof directions / sizeof directions[0];

u8 is_valid(point p) {
    return p.x >= 0 && p.y >= 0
        && p.x < w && p.y < h;
}

void bfs(int x, int y) {
    qp = q;
    *qp++ = (point){x, y};

    while (q != qp) {
        point back = *--qp;
        map[back.x][back.y] = 0;

        for (int i = 0; i < directions_len; ++i) {
            point dir = directions[i];
            point next = add(back, dir);
            if (is_valid(next) && map[next.x][next.y] == 1) {
                *qp++ = next;
            }
        }
    }
    count += 1;
}


int main(void) {}
// int main(void) {
int __libc_start_main(void) {
    _Alignas(64) char srcbuf[SRC_SIZE];
    _Alignas(64) char sinkbuf[SINK_SIZE];

    struct io *src = &(struct io){.buf = srcbuf};
    struct io *sink = &(struct io){.buf = sinkbuf};

    while (1) {
        w = get_uint(src), h = get_uint(src);
        if (w == 0)
            break;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                u8 b = get_c(src) - '0';
                get_c(src);
                map[j][i] = b;
            }
        }

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (map[j][i])
                    bfs(j, i);
            }
        }
        put_int(sink, count);
        put_c(sink, '\n');
        count = 0;
    }

    write(STDOUT_FILENO, sinkbuf, sink->cur);
    _exit(0);
}

inline static void try_flush(struct io *io, u64 size) {
    if (unlikely(io->cur + size == SINK_SIZE)) {
        write(STDOUT_FILENO, io->buf, io->cur);
        io->cur = 0;
    }
}

inline static void flush(struct io *io) {
    write(STDOUT_FILENO, io->buf, io->cur);
}
