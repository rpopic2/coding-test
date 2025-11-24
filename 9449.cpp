#include <iostream>
#include <vector>
#include <cmath>

int foo(int X, int x) {
    auto f = static_cast<float>(std::max(X - x - 1, 0));
    auto g = (float)(x * 2);
    auto ret = std::ceil(f / g) + 1;
    printf("f: %f, g: %f, ret: %f\n", f, g, ret);
    return ret;
}

int main() {
    int W, H, w, h;
    std::cin >> W >> H >> w >> h;
    auto x = foo(W, w);
    auto y = foo(H, h);
    printf("%d, %d\n", x, y);
    std::cout << x * y;
}

