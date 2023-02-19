#include <iostream>
#include <chrono>
#include <cmath>
#include<vector>
using namespace std;
using namespace chrono;

vector<int> v1(10000000, 0);
vector<int> v2(10000000, 0);

void iterFor()
{
    auto e = v2.end();

    system_clock::time_point start = system_clock::now();

    for (auto iter = v2.begin(); iter != e; ++iter)
    {
        *iter = 100;
    }

    duration<double>sec = system_clock::now() - start;

    std::cout << "Iterfor : " << sec.count() << '\n';
}
void RBfor()
{ 
    system_clock::time_point start = system_clock::now();


    for (auto& rg : v1)
    {
        rg = 100;
    }

    duration<double>sec = system_clock::now() - start;
    std::cout << "RBfor : " << sec.count() << '\n';
}


int main()
{
    iterFor();
    RBfor();
}
