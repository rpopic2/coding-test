#include <iostream>
#include <algorithm>
using namespace std;

int hansus[] = {
111,123,135,147,159,
210,222,234,246,258,
321,333,345,357,369,
420,432,444,456,468,
531,543,555,567,579,
630,642,654,666,678,
741,753,765,777,789,
840,852,864,876,888,
951,963,975,987,999,
};

int main() {
    int N;
    cin >> N;

    if (N <= 99) {
        std::cout << N;
        return 0;
    }

    auto bound = std::upper_bound(begin(hansus), end(hansus), N);
    auto distance = std::distance(begin(hansus), bound);
    std::cout << 99 + distance;
}

// 1~99
