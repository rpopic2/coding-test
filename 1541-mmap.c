#pragma GCC optimize("O2")
#pragma GCC target("arch=haswell")
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

typedef unsigned u32;
#define BUF_SIZE 50
char *buf;
u32 cur, end;

char peek() {
    // if (cur == end) {
    //     cur = 0;
    //     // end = syscall(0, 0, buf, BUF_SIZE);
    //     // end = fread(buf, sizeof (char), BUF_SIZE, stdin);
    //     if (!end)
    //         return 0;
    // }
    return buf[cur];
}

char get_c() {
    peek();
    return buf[cur++];
}


int get_int() {
    int ret = 0;

    char current = get_c();

    // while (current <= ' ') {
    //     getc();
    // }
    while (current >= '0') {
        ret = ret * 10 + current - '0';
        current = get_c();
    }
    cur-=1;

    return ret;
}


int __libc_start_main() {

    struct stat stat;
    fstat(0, &stat);
    buf = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, 0, 0);
    // end = stat.st_size;

    int acc = 0;
    char sign = '+';
    while (1) {
        if (!peek())
            break;
        int n = get_int();
        if (sign == '+') {
            acc += n;
        } else {
            int minus_acc = n;
            while (peek() == '+') {
                get_c();
                n = get_int();
                minus_acc += n;
            }
            acc -= minus_acc;
        }
        // std::cout << "found " << i << std::endl;
        // printf("sign '%d'\n", cur);
        sign = get_c();
    }

    char obuf[1024], *q = obuf;

    int num = acc;
    if (num < 0) {
        *q++ = '-';
        num = -num;
    }
    int digits = 1;
    for (int j = num; j >= 10; j /= 10) ++digits;
    for (int j = digits; j--; num /= 10) q[j] = num % 10 + '0';
    q += digits;
    syscall(1, 1, obuf, q - obuf);

    // printf("%d", acc);
    // fflush(stdout);
    _exit(0);
}
int main;

// -1-2-3-4-5
// all plus/minus-> just add
// 55-50+40
// 55-50-80
// 55-50+40-90+100-70



