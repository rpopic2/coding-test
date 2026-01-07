#include <cstdio>
#include <utility>

int main() {
	int n;
	scanf("%d", &n);

	int acc = 1;
	int acc2 = 1;

	for (int i = 1; i < n; ++i) {
		acc += acc2;
		acc %= 15746;
		std::swap(acc, acc2);
	}
	printf("%d", n);
}

// 1
// 1

// 2:
// 11 00

// 3:
// 111 001 100

// 4:
// 1111 0011 1001 1100 0000

// 5:
// 11111 00111 10011 11001 00001
// 11100 00100 10000 


