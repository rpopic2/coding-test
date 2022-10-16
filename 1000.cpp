#include<iostream>
using namespace std;
int main()
{
    unsigned long long n, m;
    cin >> n >> m;
    if (m == 0) return 0;
    std::cout << n / m << endl;
    std::cout << n % m;
    return 0;
}