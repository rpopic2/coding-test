#include <iostream>
#include <vector>
#include <limits>

#define range_in(name, end) for (int name = 0; name < (end); ++name)

unsigned get_uint(std::istream &src) {
    unsigned u;
    src >> u;
    return u;
}

enum color {
    R, G, B, NONE
};
const char *colname[] = {
    "Red", "Green", "Blue", "None",
};

int main() {
    // std::cin.tie(nullptr)->sync_with_stdio(false);
    auto n = get_uint(std::cin);

    std::vector<std::vector<unsigned>> vecs(3, std::vector<unsigned>(n));
    std::vector<std::vector<color>> nexts(3, std::vector<color>(n));
    //
    // auto r = get_uint(std::cin);
    // auto g = get_uint(std::cin);
    // auto b = get_uint(std::cin);
    // rvec[0] = gvec[0] = bvec[0] = std::min({r, g, b});

    std::vector<unsigned> results(n, std::numeric_limits<unsigned>::max());
    std::vector<color> cur_cols(n, NONE);

    range_in(i, n) {
        auto r = get_uint(std::cin);
        auto g = get_uint(std::cin);
        auto b = get_uint(std::cin);

        if (g < b) vecs[R][i] = g, nexts[R][i] = G;
        else vecs[R][i] = b, nexts[R][i] = B;

        if (r < b) vecs[G][i] = r, nexts[G][i] = R;
        else vecs[G][i] = b, nexts[G][i] = B;

        if (r < g) vecs[B][i] = r, nexts[B][i] = R;
        else vecs[B][i] = g, nexts[B][i] = G;

        // vecs[R][i] = std::min(g, b);
        // vecs[G][i] = std::min(r, b);
        // vecs[B][i] = std::min(r, g);

        int min = std::numeric_limits<unsigned>::max();
        color min_color;
        if (r < min) min = r, min_color = R;
        if (g < min) min = g, min_color = G;
        if (b < min) min = b, min_color = B;

        results[i] = min;
        cur_cols[i] = min_color;
        for (int j = i - 1; j >= 0; --j) {
            results[i] += vecs[min_color][j];
            min_color = nexts[min_color][j];
        }
        for (int j = i - 1; j >= 0; --j) {
            color next_color = cur_cols[j];
            results[j] += vecs[next_color][i];
            cur_cols[j] = nexts[next_color][i];
        }

        // range_in (k, i+1) {
        //     std::cout << k << ":" << results[k] << '(' << colname[cur_cols[k]] << ')' << '\n';
        // }
        // std::cout << '\n';
    }

    unsigned min = std::numeric_limits<unsigned>::max();
    for (auto r : results) {
        if (r < min)
            min = r;
    }
    std::cout << min << '\n';
}

