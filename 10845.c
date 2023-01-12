#include <stdio.h>
#include <string.h>
#define MAX_N 10000
#define MAX_CMD_LEN 6

int queue[MAX_N];
int push_ptr = 0, pop_ptr = 0;

int size() {
    return push_ptr - pop_ptr;
}
void push(int i) {
    queue[push_ptr++] = i;
}
int pop() {
    if (size() == 0) return -1;
    return queue[pop_ptr++];
}
int front() {
    if (size() == 0) return -1;
    return queue[pop_ptr];
}
int back() {
    if (size() == 0) return -1;
    return queue[push_ptr - 1];
}
int empty() {
    return size() == 0;
}
int cmd_equal(const char *lhs, const char *rhs) {
    return lhs[0] == rhs[0] && lhs[1] == rhs[1];
}
int main(void) {
    FILE *stdin_fd = fdopen(0, "rm");
    FILE *stdout_fd = fdopen(1, "wm");
    int N;
    fscanf(stdin_fd, "%d", &N);
    char cmd[MAX_CMD_LEN];
    int result;
    for (int i = 0; i < N; ++i) {
        fscanf(stdin_fd, "%s", cmd);
        if (cmd_equal(cmd, "push")) {
            int arg;
            fscanf(stdin_fd, "%d\n", &arg);
            push(arg);
            continue;
        } else if (cmd_equal(cmd, "pop")) {
            result = pop();
        } else if (cmd_equal(cmd, "size")) {
            result = size();
        } else if (cmd_equal(cmd, "empty")) {
            result = empty();
        } else if (cmd_equal(cmd, "front")) {
            result = front();
        } else if (cmd_equal(cmd, "back")) {
            result = back();
        }
        fprintf(stdout_fd, "%d\n", result);
    }
}
