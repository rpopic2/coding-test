#include <algorithm>
#include <iostream>
#include <string_view>
#include <unordered_map>
#include <vector>

using namespace std;

class user
{
public:
    using reporters = std::vector<std::string_view>;
    user() {}
    user(const std::string &name) : _name(name) {}

    void reported_by(std::string_view reporter)
    {
        auto iter = std::find(_reporters.begin(), _reporters.end(), reporter);
        if (iter != _reporters.end())
            return;
        _reporters.push_back(reporter);
        ++_reported;
    }

    const reporters &get_reporters() const
    {
        return _reporters;
    }

    int mails() const { return _mails; }

    void receive_mail() { ++_mails; }

    int reported() const { return _reported; }


private:
    std::string_view _name;
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
        auto *p = s.c_str();
        map[p] = {p};
    }

    for (const auto &s : report) {
        auto idx = s.find(' ');
        if (idx == std::string::npos)
            continue;
        std::string_view reporter(s.c_str(), idx);
        std::string_view target(s.c_str() + idx + 1);
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

