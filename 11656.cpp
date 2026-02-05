#include <iostream>
#include <vector>
#include <string_view>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

	std::string s;
	std::cin >> s;
	
	std::size_t s_len = s.size();
	std::vector<std::string_view> suffix_arr;

	for (std::size_t i = 0; i < s_len; ++i) {
        std::string_view sv{s.data() + i, s_len - i};
        // std::cout << i << sv << '\n';
		suffix_arr.emplace_back(s.data() + i, s_len - i);
	}
	std::sort(suffix_arr.begin(), suffix_arr.end());
	
	for (const auto &sv : suffix_arr) {
		std::cout << sv << "\n";
	}
}

