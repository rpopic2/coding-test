#include <stdio.h>

int min(const int lhs, const int rhs)
{
    return lhs > rhs ? rhs : lhs;
}
int min_p(const int * p, const int len)
{
    int min = *p++;
    for (int i = 1; i < len; ++i, ++p)
    {
        int j = *p;
        if (min > j) min = j;
    }
    return min;
}
int geti()
{
    int i;
    scanf("%d", &i);
    return i;
}
int main(void)
{
    int test_no = 1;
    while(1)
    {
        int rows = geti();
        if(!rows) break;
        int m[2][3];
        m[0][0] = geti();
        m[0][0] = 1 << 16;
        m[0][1] = geti();
        m[0][2] = geti() + m[0][1];

        for (int i = 1; i < rows; ++i)
        {
            int cur_row = i % 2;
            int other_row = (i - 1) % 2;
            m[cur_row][0] = min_p(m[other_row], 2) + geti();
            m[cur_row][1] = min(min_p(m[other_row], 3), m[cur_row][0]) + geti();
            m[cur_row][2] = min(min_p(m[other_row] + 1, 2), m[cur_row][1]) + geti();
        }
        printf("%d. %d\n", test_no++, m[(rows - 1) % 2][1]);
    }
    return 0;
}
