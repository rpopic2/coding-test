// #include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

constexpr int WALLS = 3;

int width, height;

enum entity {
    EMPTY, WALL, VIRUS
};

struct coord {
    int x, y;

    coord operator+(const coord &rhs) {
        return {x + rhs.x, y + rhs.y};
    }

    bool operator!=(const coord &rhs) {
        return x != rhs.x || y != rhs.y;
    }
    bool operator==(const coord &rhs) {
        return x == rhs.x && y == rhs.y;
    }

};
constexpr static coord NPOS{-1, -1};

struct wall_tuple {
    union {
        struct {
            coord wall1, wall2, wall3;
        };
        coord get[WALLS];
    };
};

using matrix = std::vector<std::vector<int>>;

enum direction {
    LEFT, RIGHT, UP, DOWN
};
const coord directions[4] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

void print_map(const matrix &map) {
    // std::cout << "map: \n";
    // auto width = map.size();
    // auto height = map[0].size();
    // for (int i = 0; i < height; ++i) {
    //     for (int j = 0; j < width; ++j) {
    //         std::cout << map[j][i] << ' ';
    //     }
    //     std::cout << '\n';
    // }
}

auto is_valid (int width, int height, coord c) -> bool {
    return c.x >= 0 && c.y >= 0 && c.x < width && c.y < height;
};

void spread(matrix &map, const coord virus) {
    auto width = map.size();
    auto height = map[0].size();

    std::queue<coord> q;
    q.push(virus);

    while (!q.empty()) {
        coord v = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            coord tmp = v + directions[i];
            if (is_valid(width, height, tmp) && map[tmp.x][tmp.y] == EMPTY) {
                q.push(tmp);
                map[tmp.x][tmp.y] = VIRUS;
            }
        }
    }
}

coord next_empty(const coord start, matrix &map) {
    coord ret = start;
    ret.x += 1;
    if (ret.x >= width) {
        ret.x = 0;
        ret.y += 1;
    } else if (ret.y >= height) {
        // printf("y too big");
        return NPOS;
    }

    int x = ret.x;
    for (int y = ret.y; y < height; ++y) {
        for (; x < width; ++x) {
            // printf("%d, %d\n", x, y);
            if (map[x][y] == EMPTY) {
                map[x][y] = WALL;
                return{x, y};
            }
        }
        x = 0;
    }
        // printf("reached end %d %d", height, width);
    return NPOS;
}

// coord next_coord(const coord start, matrix &map) {
//     // for (int x = start.x; x < map.size(); ++x) {
//     //     for (int y = start.y; y < map[x].size(); ++y) {
//     //         if (x == start.x && y == start.y)
//     //             continue;
//     //         return{x, y};
//     //     }
//     // }
//     // return NPOS;
//
// }

int simulate(matrix &&map, const std::vector<coord> viruses) {
    // std::cout << ">> start simulation ";
    // print_map(map);
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    auto width = map.size();
    auto height = map[0].size();

    for (const auto v : viruses) {
        // std::printf("spreading virus at %d, %d ", v.x, v.y);
        spread(map, v);
        // print_map(map);
    }

    int acc = 0;
    for (const auto &v : map) {
        for (auto r : v) {
            if (r == EMPTY) {
                acc += 1;
            }
        }
    }
    // if (acc > 0) {
    //     print_map(map);
    // }
    // std::cout << "safe area: " << acc << std::endl;
    return acc;
}


int max_safe_area = 0;

void place_wall_and_simulate(const matrix &map, const std::vector<coord> viruses, int walls) {
    coord wall3;
    while (true) {
        matrix map3 = map;
        wall3 = next_empty(wall3, map3);
        if (wall3 == NPOS)
            break;
        if (walls == 1) {
            int safe_area = simulate(std::move(map3), viruses);
            if (safe_area > max_safe_area) {
                max_safe_area = safe_area;
            }
        } else {
            place_wall_and_simulate(map3, viruses, walls - 1);
        }
    }
}

int main() {
    // std::cin >> height >> width;
    scanf("%d %d", &height, &width);

    matrix map_original(width, std::vector<int>(height));
    std::vector<coord> viruses;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            auto &room = map_original[j][i];
            scanf("%d", &room);
            // std::cin >> room;
            if (room == VIRUS) {
                viruses.emplace_back(j, i);
            }
        }
    }

    // std::printf("%d!", map_original[5][1]);
    // std::cout << "original ";
    print_map(map_original);


    coord wall1{}, wall2{}, wall3{};

    matrix map = map_original;
    wall1 = {-1, 0};
    wall2 = wall1;


    // map[0][1] = WALL;
    // map[1][0] = WALL;
    // map[5][3] = WALL;
    // print_map(map);
    // max_safe_area = simulate(std::move(map), viruses);

    place_wall_and_simulate(map, viruses, WALLS);
    printf("%d\n", max_safe_area);
}

