#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, nomal = 0, colorBlind = 0;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
vector<vector<char>> grid;
vector<vector<int>> visited;

void BFS(int startY, int startX)
{
    queue<pair<int, int>> q;
    q.push({startY, startX});
    visited[startY][startX] = 1;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || n <= ny || nx < 0 || n <= x)
                continue;
            if (visited[ny][nx])
                continue;
            if (grid[y][x] != grid[ny][nx])
                continue;

            visited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    grid.resize(n, vector<char>(n));
    visited.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (visited[i][j] == 0)
            {
                BFS(i, j);
                nomal++;
            }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 'G')
                grid[i][j] = 'R';

    for (int i = 0; i < visited.size(); i++)
        fill(visited[i].begin(), visited[i].end(), 0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (visited[i][j] == 0)
            {
                BFS(i, j);
                colorBlind++;
            }
    cout << nomal << " " << colorBlind;
    return 0;
}