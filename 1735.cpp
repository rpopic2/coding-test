#include <iostream>
#include <vector>

using uint = unsigned int;

void yakbun(uint *ja, uint *mo, uint divend) {
    while (*ja % divend == 0 && *mo % divend == 0) {
        *ja /= divend, *mo /= divend;
    }
}

uint gdc(uint ja, uint mo) {
    if (mo <= 0)
        return ja;
    return gdc(mo, ja % mo);
}

int main() {
    uint a_ja, a_mo;
    uint b_ja, b_mo;
    std::cin >> a_ja >> a_mo >> b_ja >> b_mo;

    uint r_ja, r_mo;
    r_ja = a_ja * b_mo + b_ja * a_mo;
    r_mo = a_mo * b_mo;

    uint g = gdc(r_ja, r_mo);
    // for (int i = 2; i < r_mo; ++i) {
    //     yakbun(&r_ja, &r_mo, i);
    // }

    std::cout << r_ja / g << ' ' << r_mo /g;
}

