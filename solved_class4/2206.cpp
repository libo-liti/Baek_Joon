#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int n, m, answer = INF;
vector<vector<int>> grid;
vector<vector<int>> dist;

void Search()
{
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};

    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    q.push({0, 0});
    visited.insert({0, 0});
    dist[0][0] = 1;

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
            if (visited.count({ny, nx}))
                continue;

            if (grid[ny][nx] == 0)
                q.push({ny, nx});

            dist[ny][nx] = dist[y][x] + 1;
            visited.insert({ny, nx});
        }
    }

    if (dist[n - 1][m - 1] != 0)
        answer = dist[n - 1][m - 1];

    visited.clear();
    dist[n - 1][m - 1] = 1;
    q.push({n - 1, m - 1});
    visited.insert({n - 1, m - 1});

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
            if (visited.count({ny, nx}))
                continue;

            if (grid[ny][nx] == 0)
            {
                q.push({ny, nx});
                dist[ny][nx] = dist[y][x] + 1;
                visited.insert({ny, nx});
            }
            else if (dist[ny][nx] != 0)
            {
                answer = min(answer, dist[y][x] + dist[ny][nx]);
                visited.insert({ny, nx});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    dist.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            grid[i][j] = str[j] - '0';
    }
    Search();
    if (answer != INF)
        cout << answer;
    else
        cout << -1;
    return 0;
}