#include <stdio.h>
#include <string.h>

int main(void) {
    char gap_buf[600002] = {0},
        *front = gap_buf,
        *const end = gap_buf + sizeof gap_buf - 1,
        *back = end;

    int bytes_read = scanf("%s", gap_buf); // I do understand that this is super unsafe
    front += strlen(gap_buf);

    int m;
    scanf("%d", &m);

    char scan_buf[2];

    for (int i = 0; i < m; ++i) {
        char cmd;
        scanf(" %c", &cmd);

        if (cmd == 'L') {
            if (front == gap_buf)
                continue;
            *--back = *--front;
        } else if (cmd == 'D') {
            if (back == end)
                continue;
            *front++ = *back++;
        } else if (cmd == 'B') {
            if (front == gap_buf)
                continue;
            --front;
        } else if (cmd == 'P') {
            char c;
            scanf(" %c", &cmd);
            *front++ = c;
        }
        // printf("%d: %s %s\n", i, front.c_str(), back.c_str());
    }

    // printf("first siz: %zd", (size_t)(front - gap_buf));
    fwrite(gap_buf, sizeof (char), (size_t)(front - gap_buf), stdout);
    fwrite(back, sizeof (char), (size_t)(end - back), stdout);
    putc('\n', stdout);
}


