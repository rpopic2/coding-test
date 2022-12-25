#include <algorithm>
#include <unordered_set>
#include <iostream>
using namespace std;

bool is_group_word(string word)
{
    auto iter = word.begin();
    auto iter_end = word.end();
    unordered_set<char> seen;
    while (iter != iter_end)
    {
        auto c = *iter;
        if (seen.find(c) != seen.end()) return false;
        seen.insert(c);
        do {
            ++iter;
        } while (*iter == c);
    }
    return true;
}

int main()
{
    int input_n;
    string word;
    std::cin >> input_n;
    int wc = 0;
    for (int i = input_n; i--;)
    {
        cin >> word;
        if (is_group_word(word)) ++wc;
    }
    std::cout << wc;
}
