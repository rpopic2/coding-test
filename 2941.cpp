#include <iostream>
#include <array>
using namespace std;

const array<string, 8> croatian{
    "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="
};
int main() {
    string s;
    cin >> s;
    auto counter = 0;
    for (string::size_type i = 0, len = s.length(); i < len; ++i) {
        for (const auto &crot : croatian) {
            auto crot_size = crot.size();
            auto first_two = s.substr(i, crot_size);
            if (first_two != crot) continue;
            i += crot_size - 1;
        }
        ++counter;
    }
    cout << counter;
}
