#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
    map<int, int> _map;
    int dp[101]{};
    int n, m;
    cin >> n >> m;

    fill(dp, dp + 101, 100);
    dp[1] = 0;
    dp[2] = dp[3] = dp[4] = dp[5] = dp[6] = 1;

    for (int i = 0; i < n + m; i++)
    {
        int key, value;
        cin >> key >> value;
        _map[key] = value;
    }

    for (int k = 0; k < 2; k++)
    {
        for (int i = 2; i < 101; i++)
        {
            for (int j = 6; j >= 1; j--)
            {
                if (_map.find(i - j) != _map.end())
                    continue;
                dp[i] = min(dp[i], dp[i - j] + 1);
            }

            if (_map.find(i) != _map.end())
                dp[_map[i]] = min(dp[_map[i]], dp[i]);
        }
    }

    cout << dp[100];
    return 0;
}