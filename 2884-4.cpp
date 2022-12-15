#include <iostream>
#include <array>
using namespace std;
class simple_time
{
public:
    int h_, m_;
    simple_time(int h, int m) : h_{h}, m_{m} { }
    simple_time() : h_{0}, m_{0} { }
    int &operator[](int i);
    void operator-=(simple_time &op);
    friend ostream &operator<<(ostream &os, simple_time &t);
private:
    void subtract(int index, int amount);
};
int &simple_time::operator[](int i)
{
    if (i == 0) return h_;
    else if (i == 1) return m_;
    else throw;
}
simple_time T_DEF = {24, 60};
void simple_time::subtract(int index, int amount)
{
    int *target = &(*this)[index];
    *target -= amount;
    if (*target < 0)
    {
        *target += T_DEF[index];
        if (index <= 0) return;
        subtract(index - 1, 1);
    }
}
void simple_time::operator-=(simple_time &op)
{
    for (int i = 0; i < 2; ++i)
    {
        subtract(i, op[i]);
    }
}
istream &operator>>(istream &is, simple_time &t)
{
    is >> t.h_ >> t.m_; return is;
}
ostream &operator<<(ostream &os, simple_time &t)
{
    os << t.h_ << ' ' << t.m_; return os;
}

int main()
{
    simple_time t, op = {0, 45};
    cin >> t;
    t -= op;
    cout << t;
}

