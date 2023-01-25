#include <iostream>
#include <vector>

std::vector<int> fibonacci_arr;
int fibonacci(int n) {
    if (n < 2) return n;
    int &fib_n = fibonacci_arr[n];
    if (fib_n != 0) return fib_n;
    fib_n = fibonacci(n - 2) + fibonacci(n - 1);
    return fib_n;
}

int main() {
    int n;
    std::cin >> n;
    fibonacci_arr = std::vector<int>(n, 0);
    std::cout << fibonacci(n) << std::endl;
}
