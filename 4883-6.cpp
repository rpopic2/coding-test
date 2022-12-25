#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
typedef vector<array<int, 3>> matrix;

int main()
{
    for (int test_no = 1;;++test_no)
    {
        int n;
        cin >> n;
        if (n == 0) return 0;
        matrix graph, dp;
        graph.resize(n);
        dp.resize(n);
        for (int i = 0; i < n; ++i)
        {
            array<int, 3> a;
            cin >> a[0] >> a[1] >> a[2];
            graph[i] = a;
        }
        
        dp[0] = {1 << 16, graph[0][1], graph[0][1] + graph[0][2]};
        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + graph[i][0];
            dp[i][1] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][0]}) + graph[i][1];
            dp[i][2] = min({dp[i - 1][1], dp[i - 1][2], dp[i][1]}) + graph[i][2];
        }
        cout << test_no << ". ";
        cout << dp[n - 1][1] << '\n';
    }
}
