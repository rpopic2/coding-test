#include <string_view>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class user
{
public:
    user(std::string_view name) : _name(name) {}
    
    void reported_by(std::string_view reporter)
    {
        _reporters.push_back(reporter);
        ++_reported;
    }
    
private:
    std::string_view _name;
    std::vector<std::string_view> _reporters;
    int _reported = 0;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    size_t list_size;
    std::vector<user> users;
    std::unordered_map<std::string_view, user> map;
    
    list_size = id_list.size();
    users.reserve(list_size);
    map.reserve(list_size);
    for (const auto &s : id_list) {
        auto u = users.emplace_back(s.c_str());
        map.insert({s.c_str(), u});
    }
    
    for (const auto &s : report) {
        auto idx = s.find(' ');
        std::string_view reporter(s.c_str(), idx);
        std::string_view target(s.c_str() + idx + 1);
        if (idx == std::string::npos)
            continue;
    }
    
    
    vector<int> answer;
    return answer;
}
