// deque from scratch
#include <stdio.h>
#include <string.h>

int deque[20001];
int *pfront = deque + 10000;
int *pback = deque + 9999;

int size() {
    return pfront - pback - 1;
}
int empty() {
    return size() == 0;
}
void push_front(int value) {
    *pfront++ = value;
}
void push_back(int value) {
    *pback-- = value;
}
int pop_front() {
    if (empty()) return -1;
    return *--pfront;
}
int pop_back() {
    if (empty()) return -1;
    return *++pback;
}
int front() {
    if (empty()) return -1;
    return pfront[-1];
}
int back() {
    if (empty()) return -1;
    return pback[1];
}

int main(void) {
    int N;
    scanf("%d", &N);

    char cmd[11];
    int arg;
    while (N--) {
        scanf("%s", cmd);
        if (strcmp(cmd, "push_front") == 0) {
            scanf("%d", &arg);
            push_front(arg);
        } else if (strcmp(cmd, "push_back") == 0) {
            scanf("%d", &arg);
            push_back(arg);
        } else if (strcmp(cmd, "pop_front") == 0) {
            printf("%d\n", pop_front());
        } else if (strcmp(cmd, "pop_back") == 0) {
            printf("%d\n", pop_back());
        } else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", size());
        } else if (strcmp(cmd, "empty") == 0) {
            printf("%d\n", empty());
        } else if (strcmp(cmd, "front") == 0) {
            printf("%d\n", front());
        } else if (strcmp(cmd, "back") == 0) {
            printf("%d\n", back());
        }
    }
}
