#include <unistd.h>
#include <stdio.h>

constexpr int IBUF_SIZ = 1 << 16;
auto i = 1 << 10;

char ibuf[IBUF_SIZ];
int idx = 0;
long bytes_read = 0;

inline char get() {
    if (idx == bytes_read) {
        bytes_read = syscall(0, 0, ibuf, IBUF_SIZ);
        idx = 0;
    }
    return ibuf[idx++];
}

inline int readint()
{
    char c = get();
    int result = 0;// c - '0';
    while (c >= '0')
    {
        result *= 10;
        result += c - '0';
        c = get();
    }
    return result;
}
