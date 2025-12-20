#include <iostream>
#include <vector>

int main() {
    int e, s, m;
    std::cin >> e >> s >> m;

    int E = 1, S = 1, M = 1;
    int result = 1;

    while (true) {
        if (E == e && S == s && M == m)
            break;
        E %= 15, S %= 28, M %= 19;
        E += 1, S += 1, M += 1;
        result += 1;
    }

    std::cout << result;
}

