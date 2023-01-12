#include <stdio.h>
#define MAX_SIZE 14

int main(void)
{
    int dp[MAX_SIZE + 1][MAX_SIZE];
    for (int j = 0; j < MAX_SIZE; ++j)
    {
        dp[0][j] = j + 1;
    }
    for (int i = 1; i < MAX_SIZE + 1; ++i)
    {
        dp[i][0] = 1;
        for (int j = 1; j < MAX_SIZE; ++j)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int J, K; // >> K starts from 1!! <<
        scanf("%d", &J);
        scanf("%d", &K);
        printf("%d\n", dp[J][--K]);
    }
}
