#include <iostream>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int people_in_square;
    int party_room_size;
    std::cin >> people_in_square >> party_room_size;

    int expected_people = people_in_square * party_room_size;

    int cache;
    for (int i = 0; i < 5; ++i) {
        std::cin >> cache;
        std::cout << cache - expected_people << ' ';
    }
}
