#include <iostream>
#include <vector>
#include <bitset>

class theatre {
    using size_type = std::vector<int>::size_type;
public:
    theatre(size_type size, const std::vector<int> &vips) : _size(size), _seats(_size, false) {
        for (const auto i : vips) {
            _seats[i] = true;
        }
    }

    int get_num_cases() {
        for (int i = 0; i < _size; ++i) {
            if (_seats[i] || _seats[i + 1]) {

            }
        }
    }

private:
    size_type _size;
    std::vector<bool> _seats;
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int num_seats;
    int num_vips;

    std::cin >> num_seats >> num_vips;

    std::vector<int> vip_seats;
    vip_seats.reserve(num_vips);
    for (int i = 0; i < num_vips; ++i) {
        int input;
        std::cin >> input;
        vip_seats.push_back(input);
    }

}

