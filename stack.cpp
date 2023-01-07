#include <iostream>

template <typename T>
class stack {
    int ptr = 0;
    T arr[1<<16];
public:
    void push(T val) {
        arr[ptr++] = val;
    }
    void pop() {
        --ptr;
        if (ptr < 0) ptr = 0;
    }
    T *begin() {
        return &arr[0];
    }
    T *end() {
        return &arr[ptr];
    }
};

int main() {
    stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.pop();

    for (const auto &i : stack) {
        std::cout << i << std::endl;
    }
}
