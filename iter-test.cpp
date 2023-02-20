#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>

constexpr int N = 10'000'000;

void iterFor()
{
	std::vector<int> v2(N, 0);

    auto start = std::chrono::high_resolution_clock::now();
    
    auto vector_end = v2.end();
    for (auto iter = v2.begin(); iter != vector_end; iter++)
    {
        *iter = 100;
    }

    std::chrono::duration<double> sec = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Iterfor : " << sec.count() << '\n';
}
void expanded_for() {
	std::vector<int> vec(N, 0);

     auto && range = vec;
     for (auto begin = std::begin(range), end = std::end(range); begin != end; ++begin)
     {
        auto & rg = *begin;
        rg = 100;
     }

    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sec = std::chrono::high_resolution_clock::now() - start;
    std::cout << "expanded_for : " << sec.count() << '\n';

}
void RBfor()
{ 
	std::vector<int> vec(N, 0);

    auto start = std::chrono::high_resolution_clock::now();

    for (auto& rg : vec)
    {
        rg = 100;
    }
    // is equivalant to
    // auto && range = vec;
    // for (auto begin = std::begin(range), end = std::end(range); begin != end; ++begin)
    // {
    //    auto & rg = *begin;
    //    rg = 100;
    // }

    std::chrono::duration<double> sec = std::chrono::high_resolution_clock::now() - start;
    std::cout << "RBfor : " << sec.count() << '\n';
}


int main()
{
    iterFor();
    expanded_for();
    RBfor();
}
