// #include <iostream>
#include <cstdio>
#include <unistd.h>

#include <stdint.h>

using u32 = uint32_t;
constexpr int BUF_SIZE = 1 << 16;
char buf[BUF_SIZE];
u32 cur, end;

char getc() {
    if (cur == end) {
        cur = 0;
        end = fread(buf, sizeof (char), BUF_SIZE, stdin);
        if (!end)
            return 0;
    }
    return buf[cur++];
}

int get_int() {
    int ret = 0;

    char current = getc();

    while (current <= ' ') {
        getc();
    }
    while (current >= '0') {
        ret = ret * 10 + current - '0';
        current = getc();
    }

    return ret;
}

int __libc_start_main() {
    // std::cin.tie(nullptr)->sync_with_stdio(false);
    int n = get_int();
    // std::cin >> n;

    int stack[n + 1];
    int *cur = stack;
    int last = 0;
    char buffer[1<<19];
    char *w = buffer;
    // std::ostringstream buffer(n * 2);

    for (int i = 0; i < n; ++i) {
        int x = get_int();
        // std::cin >> x;
        // printf("cur %d\n", x);

        if (x > last) {
            for (int j = last + 1; j <= x; ++j) {
                *cur++ = j;
                // printf("push %d\n", j);
                // buffer << "+\n";
                *w++ = '+';
                *w++ = '\n';
            }
            last = x;
        }
loop:
        if (cur == stack) {
            // std::cout << "NO\n";
            printf("NO\n");
            return 0;
        }
        int back = *--cur;//stack.back();
        // stack.pop_back();
        // printf("pop %d\n", back);
        // buffer << "-\n";

        *w++ = '-';
        *w++ = '\n';
        if (back != x)
            goto loop;
    }
    *w++ = '\0';
    // std::cout << buffer;
    // printf("%s", buffer);
    write(STDOUT_FILENO, buffer, w - buffer -1);
    _exit(0);
}
int main(void) {}

