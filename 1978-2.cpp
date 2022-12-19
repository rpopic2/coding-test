#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void get_inputs(std::vector<int> *inputs)
{
    std::cin.ignore(10, '\n');
    for (int i; std::cin >> i;)
    {
        inputs->push_back(i);
    }
}
void generate_primes(std::unordered_map<int, bool> *primes, int max)
{
    primes->insert(std::pair<int, bool>(2, true));
    for (int i = 3; i <= max; ++i)
    {
        bool is_prime = true;
        for (const auto &j : *primes)
        {
            if (i % j.first == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
        {
            primes->insert(std::pair<int, bool>(i, true));
        }
    }
}
int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::vector<int> inputs;
    std::unordered_map<int, bool> primes;
    get_inputs(&inputs);
    int max = 0;
    max = *std::max_element(inputs.begin(), inputs.end());
    generate_primes(&primes, max);
    
    int cnt_primes = 0;
    for (const auto &i : inputs)
    {
        if (primes[i])
        {
            ++cnt_primes;
        }
    }
    std::cout << cnt_primes;
}
