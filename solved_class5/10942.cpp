#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<vector<int>> dp;
int n, m;

void Solution()
{
    // 순회 방향이 대각선
    for (int plus = 0; plus < n; plus++)
        for (int start = 0; start + plus <= n; start++)
        {
            if (plus == 0)
                dp[start][start] = 1;
            else if (plus == 1 && v[start] == v[start + plus])
                dp[start][start + plus] = 1;
            else if (v[start] == v[start + plus] && dp[start + 1][start + plus - 1])
                dp[start][start + plus] = 1;
        }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    v.resize(n + 1, 0);
    dp.resize(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < n + 1; i++)
        cin >> v[i];

    Solution();

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int s, e, answer;
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
    return 0;
}