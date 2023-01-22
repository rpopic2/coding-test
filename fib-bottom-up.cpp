#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> fibonacci_arr(n);
    fibonacci_arr[0] = 0;
    fibonacci_arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        fibonacci_arr[i] = fibonacci_arr[i-1] + fibonacci_arr[i-2];
    }

    std::cout << fibonacci_arr[n] << std::endl;
}
