#include <chrono>
#include <iostream>
using namespace std;
using namespace chrono;


int main()
{
    long i, j;
    cin >> i >> j;
    hours h(i);
    minutes m(j);
    minutes sum = duration_cast<minutes>(h);
    sum += m;
    sum -= minutes(45);
    
    h = duration_cast<hours>(sum);
    m = sum - duration_cast<minutes>(h);
    cout << h << m;
}
