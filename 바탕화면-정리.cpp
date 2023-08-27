#include <string>
#include <vector>

using namespace std;

constexpr size_t npos = -1;

size_t index_of_file(const std::string &s) {
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == '#')
            return i;
    }
    return npos;
}

size_t last_index_of_file(const std::string &s, size_t end) {
    for (size_t i = end; i >= 0; --i) {
        char c = s[i];
        if (c == '#')
            return i;
    }
    return 0;
}

vector<int> solution(vector<string> wallpaper) {
    size_t size = wallpaper.size();
    size_t end = wallpaper[0].size() - 1;

    size_t min_x = npos;
    size_t min_y = npos;
    size_t max_x = 0;
    size_t max_y = 0; 

    for (size_t i = 0; i < size; ++i) {
        auto &line = wallpaper[i];

        size_t min = index_of_file(line);
        if (min == npos)
            continue;
        if (min < min_x)
            min_x = min;

        size_t max = last_index_of_file(line, end);
        if (max > max_x)
            max_x = max;

        if (i < min_y)
            min_y = i;
        max_y = i;
    }

    vector<int> answer {
        static_cast<int>(min_y),
        static_cast<int>(min_x),
        static_cast<int>(max_y + 1),
        static_cast<int>(max_x + 1)
    };
    return answer;
}

