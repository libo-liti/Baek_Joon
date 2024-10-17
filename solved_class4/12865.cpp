#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, value, weight;
    cin >> n >> k;

    // 배열 할당 및 초기화
    // 배열 1부터 시작하기 위해 n + 1, k + 1
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new int[k + 1];
        fill(dp[i], dp[i] + k + 1, 0);
    }

    // DP
    for (int i = 1; i <= n; i++)
    {
        cin >> weight >> value;
        // i번째 물건을 최대 가방 무게 k에 넣을때 최대 가치
        for (int j = 1; j <= k; j++)
        {
            if (j < weight)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
        }
    }
    cout << dp[n][k];

    // 메모리 해제
    for (int i = 0; i < n + 1; i++)
        delete[] dp[i];
    delete[] dp;

    return 0;
}