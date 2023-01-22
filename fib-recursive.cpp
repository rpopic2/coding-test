#include <iostream>
int fibonacci(int index) {
		if (index < 2) return index;
		return fibonacci(index - 1) + fibonacci(index - 2);
}
int main() {
    int fib;
    std::cin >> fib;
    std::cout << fibonacci(fib) << std::endl;
}
