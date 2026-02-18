#pragma GCC optimize("O2")
#pragma GCC target("arch=haswell")

#include <unistd.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned u32;
typedef unsigned long long u64;

// #define unlikely(x) __builtin_expect(!!(x), 0)
#define unlikely(x) (x)
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
#include <stdbool.h>

typedef int i32;

typedef struct point {
    i32 x; i32 y;
} point;

const point directions[] = {
    {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
    {2, -1}, {1, -2}, {-1, -2}, {-2, -1},
};
const int directions_len = sizeof directions / sizeof (point);

bool is_valid(u32 size, point p) {
    return p.x >= 0 && p.y >= 0
        && p.x < size && p.y < size;
}

typedef struct bfs_entry {
    point p;
    u32 moves;
} bfs_entry;

#define Q_SIZE (1 << 17)
bfs_entry q[Q_SIZE], *qfront = q, *qback = q, * const qcap = q + Q_SIZE;
forceinline
void q_push(bfs_entry e) {
    *qback++ = e;
    // if (qback >= qcap) {
    //     printf("overflow!\n");
    // }
}

forceinline
bfs_entry q_pop() {
    bfs_entry ret = *qfront++;
    // if (qfront > qback) {
    //     printf("back catch!\n");
    // }
    return ret;
}

bool visited[300][300];
void visited_clear(u32 size) {
    while (size--) {
        memset(visited[size], 0, sizeof (visited[size]));
    }
    qfront = q, qback = q;
}

bool point_eq(point lhs, point rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
point point_add(point lhs, point rhs) {
    return (point){lhs.x + rhs.x, lhs.y + rhs.y};
}


u32 bfs(u32 size, point src, point dst) {
    visited_clear(size);

    q_push((bfs_entry){src, 0});

    while (qfront < qback) {
        bfs_entry entry = q_pop();
        point back = entry.p;
        u32 moves = entry.moves;
        // printf("visitd %d, %d (%d)\n", back.x, back.y, moves);
        if (point_eq(back, dst)) {
            return moves;
        }

        for (int i = 0; i < directions_len; ++i) {
            point d = directions[i];
            point target = point_add(back, d);
            if (!is_valid(size, target))
                continue;
            if (visited[target.x][target.y])
                continue;
            // printf("push %d, %d (%d)\n", target.x, target.y, moves+1);
            if (point_eq(target, dst)) {
                return moves + 1;
                break;
            }
            visited[target.x][target.y] = true;
            q_push((bfs_entry){target, moves + 1});
        }
    }
    return 0;
}

point get_point(struct io *io) {
    return (point){.x = get_uint(io), .y = get_uint(io)};
}

// int main(void) {}
int main(void) {
// int __libc_start_main(void) {
    _Alignas(64) u8 srcbuf[SRC_SIZE];
    _Alignas(64) u8 sinkbuf[SINK_SIZE];

    struct io *src = &(struct io){.buf = srcbuf};
    struct io *sink = &(struct io){.buf = sinkbuf};

    u32 tc = get_uint(src);

    while (tc--) {
        u32 i = get_uint(src);
        struct point start = get_point(src),
                     dst = get_point(src);

        put_uint(sink, bfs(i, start, dst));
        put_c(sink, '\n');
    }

    flush(sink);
    _exit(0);
}

