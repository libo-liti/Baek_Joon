#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    int dp[16][16][3] = {};
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    dp[0][1][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && (j == 0 || j == 1))
                continue;

            // 가로 전이
            if (j - 1 >= 0 && graph[i][j] != 1)
                dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];

            // 세로 전이
            if (i - 1 >= 0 && graph[i][j] != 1)
                dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];

            // 대각선 전이
            if (i - 1 >= 0 && j - 1 >= 0)
                if (graph[i][j] != 1 && graph[i - 1][j] != 1 && graph[i][j - 1] != 1)
                    dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
        }
    }
    cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
    return 0;
}