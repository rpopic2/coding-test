#include <iostream>
class line
{
public:
    line(long long _x, long long _y)
    {
        x = _x;
        y = _y;
    }
    bool in_range(line cmp)
    {
        if (x <= cmp.x)
        {
            
        }
    }
    long long x, y;
};

int main()
{
    int N;
    std::cin >> N;
    long long x,y;
    std::cin >> x >> y;
    line ln(x, y);
    
    for (int i = 1; i < N; ++i)
    {
        
    }
}
