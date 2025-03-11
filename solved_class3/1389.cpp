#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    // init
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist;
    dist.resize(n + 1, vector<int>(n + 1, n + 1));

    // input
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;

        dist[s][e] = 1;
        dist[e][s] = 1;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    dist[i][j] = 0;
                    continue;
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }

    int answer, _min = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
            sum += dist[i][j];
        if (sum < _min)
        {
            answer = i;
            _min = sum;
        }
    }
    cout << answer;
    return 0;
}