#include <iostream>
#include <vector>
#include <algorithm>

void get_inputs(std::vector<int> *inputs)
{
    int cnt;
    std::cin >> cnt;
    for (int i; std::cin >> i;)
    {
        inputs->push_back(i);
    }
}
void generate_primes(std::vector<int> *primes, int max)
{
    primes->push_back(2);
    for (int i = 3; i <= max; ++i)
    {
        bool is_prime = true;
        for (const auto &j : *primes)
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
        {
            primes->push_back(i);
        }
    }
}
int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::vector<int> inputs, primes;
    get_inputs(&inputs);
    int max = 0;
    max = *std::max_element(inputs.begin(), inputs.end());
    generate_primes(&primes, max);
    
    int cnt_primes = 0;
    for (const auto &i : inputs)
    {
        if (*std::find(primes.begin(), primes.end(), i) == i)
        {
            ++cnt_primes;
        }
    }
    std::cout << cnt_primes;
}
