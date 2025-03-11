#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int dy[4] = {0, 0, -1, 1};
    int dx[4] = {1, -1, 0, 0};

    vector<vector<int>> grid(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    q.push({0, 0});

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            grid[i][j] = s[j] - '0';
    }

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || n <= ny || nx < 0 || m <= nx)
                continue;
            if (grid[ny][nx] != 1)
                continue;

            q.push({ny, nx});
            grid[ny][nx] = grid[y][x] + 1;
        }
    }
    cout << grid[n - 1][m - 1];
    return 0;
}