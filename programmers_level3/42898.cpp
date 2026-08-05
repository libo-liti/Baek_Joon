#include <string>
#include <vector>
#include <queue>

using namespace std;
const int N = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i < puddles.size(); i++)
    {
        int x = puddles[i][0];
        int y = puddles[i][1];

        dp[y][x] = 0;
    }

    dp[1][1] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (dp[i][j] != -1)
                continue;

            if (i - 1 == 0)
                dp[i][j] = dp[i][j - 1];
            else if (j - 1 == 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % N;
        }
    }
    answer = dp[n][m];

    return answer;
}