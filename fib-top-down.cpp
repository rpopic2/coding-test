#include <iostream>
#include <vector>

std::vector<int> fibonacci_arr;
int fibonacci(int n) {
    if (n < 2) return n;
    if (fibonacci_arr[n] != 0) {
        return fibonacci_arr[n];
    }
    fibonacci_arr[n] = fibonacci(n - 2) + fibonacci(n - 1);
    return fibonacci_arr[n];
}

int main() {
    int n;
    std::cin >> n;
    fibonacci_arr = std::vector<int>(n, 0);
    std::cout << fibonacci(n) << std::endl;
}
