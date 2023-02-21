#pragma GCC optimize("Ofast")
#include <unistd.h>
constexpr int IBUF_SIZ = 1 << 16;

char ibuf[IBUF_SIZ];
int idx = 0;
size_t bytes_read = 0;

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

int main() {
    // read input
    int N, K;
    N = readint();
    K = readint();
    int cage[1'000'000]{};
    int cage_size = 0;

    // read ice buckets from input
    for (int ice, pos, i = 0; i < N; ++i) {
        ice = readint(), pos = readint();
        cage[pos] = ice;
        if (pos + 1 > cage_size) cage_size = pos + 1;
    }

    // returns the value at the given index, or 0 if out of bounds

    int current_max = 0;

    // from zero width window, till the bear gets to the end of the cage
    for (int j = -K ; j <= cage_size - K - 1; ++j) {
        int left = j - K - 1;
        int right = j + K;

        static int current_window = 0;
        // move the window
        if (left >= 0) current_window -= cage[left];
        if (right < cage_size) current_window += cage[right];

        // update current max
        if (current_window > current_max)  current_max = current_window;
    }

    char obuf[1024], *q = obuf;

    int num = current_max;
    int digits = 1;
    for (int j = num; j >= 10; j /= 10) ++digits;
    for (int j = digits; j--; num /= 10) q[j] = num % 10 + '0';
    q += digits;

    syscall(1, 1, obuf, q - obuf);
}


