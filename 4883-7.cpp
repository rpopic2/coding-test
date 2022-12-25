#include <algorithm>
#include <iostream>
#include <array>
using namespace std;
typedef array<array<int, 3>, 2> matrix;

inline int read()
{
    int i;
    cin >> i;
    return i;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_no = 1;
    while (true)
    {
        int rowc = read();
        if (rowc == 0) return 0;
        matrix m;
        cin >> m[0][0];
        m[0][0] = 1 << 16; m[0][1] = read(); m[0][2] = m[0][1] + read();
        
        for (int i = 1; i < rowc; ++i)
        {
            int cur_row = i % 2;
            int other_row = (i - 1) % 2;
            m[cur_row][0] = min(m[other_row][0], m[other_row][1]) + read();
            m[cur_row][1] = min({m[cur_row][0], m[other_row][0], m[other_row][1], m[other_row][2]}) + read();
            m[cur_row][2] = min({m[cur_row][1], m[other_row][1], m[other_row][2]}) + read();
        }
        cout << test_no++ << ". ";
        cout << m[(rowc - 1) % 2][1] << '\n';
    }
}
