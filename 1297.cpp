#include <iostream>
#include <cmath>

int main()  {
    int diag;
    int h, w;
    std::cin >> diag >> h >> w;


    auto x = std::sqrt(double(diag * diag) / (h * h + w * w));

    int actual_h = floor(h * x);
    int actual_w = floor(w * x);

    std::cout << actual_h << ' ' << actual_w << '\n';
}
