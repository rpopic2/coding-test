#include <algorithm>
#include <iostream>
#include <string_view>
#include <unordered_map>
#include <vector>

using namespace std;

class user // 코테에서의 oop?
{
public:
    using reporters = std::vector<std::string_view>;

    void reported_by(const std::string_view &reporter)
    {
        auto iter = std::find(_reporters.begin(), _reporters.end(), reporter);
        if (iter != _reporters.end())
            return;
        _reporters.push_back(reporter);
        ++_reported;
    }

    inline
    const reporters &get_reporters() const { return _reporters; }

    inline
    int mails() const { return _mails; }

    inline
    void receive_mail() { ++_mails; }

    inline
    int reported() const { return _reported; }


private:
    reporters _reporters;
    int _reported = 0;
    int _mails = 0;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    size_t list_size = id_list.size();
    std::unordered_map<std::string_view, user> map;

    map.reserve(list_size);
    for (const auto &s : id_list) {
        map[s] = user{};
    }

    for (const auto &s : report) {
        auto idx = s.find(' ');
        if (idx == std::string::npos) // 문제 조건으로 아닌게 보장되어있는데 체크 해야할까
            continue;
        auto *p = s.c_str();
        std::string_view reporter(p, idx);
        std::string_view target(p + idx + 1);
        map[target].reported_by(reporter);
    }

    for (const auto &[key, u] : map) {
        if (u.reported() >= k) {
            for (const auto &rep : u.get_reporters()) {
                map[rep].receive_mail();
            }
        }
    }

    vector<int> answer;

    answer.reserve(list_size);
    for (const auto &id : id_list) {
        answer.push_back(map[id].mails());
    }

    return answer;
}

