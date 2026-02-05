#pragma GCC optimize("O2")
#pragma GCC target("arch=haswell")

#define BUF_SIZE 1 << 10
char buf[BUF_SIZE], *cur = buf;

int get_int() {
    int ret = 0;

    char current = *cur++;

    while (current >= '0') {
        ret = ret * 10 + current - '0';
        current = *cur++;
    }

    return ret;
}

char obuf[1024], *q = obuf;
void put_int(int num) {
    // if (num < 0) {
    //     *q++ = '-';
    //     num = -num;
    // }
    int digits = 1;
    for (int j = num; j >= 10; j /= 10)
        ++digits;
    for (int j = digits; j--; num /= 10)
        q[j] = num % 10 + '0';
    q += digits;
}

void put_c(char c) {
    *q++ = c;
}

int __libc_start_main() {
    syscall(0, 0, buf, BUF_SIZE);
    // read(0, buf, BUF_SIZE);

    int n = get_int(), m = get_int();

    int baskets[101];

    for (int i = 1; i <= n; ++i) {
        baskets[i] = i;
    }

    while (m--) {
        int l = get_int(), r = get_int();

        while(l < r) {
            int tmp = baskets[l];
            baskets[l] = baskets[r];
            baskets[r] = tmp;
            l++, r--;
		}
    }

    for (int i = 1; i <= n; ++i) {
        put_int(baskets[i]);
        put_c(' ');
    }
    syscall(1, 1, obuf, q - obuf);
    // write(1, obuf, q - obuf);
    _exit(0);
}

int main;
