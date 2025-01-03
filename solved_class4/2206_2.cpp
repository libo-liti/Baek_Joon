#include <iostream>
#include <queue>
using namespace std;

int n, m, answer;
int grid[1001][1001];
int visited[1001][1001][2];

struct Pos
{
    int y;
    int x;
    int wall;
};

void BFS()
{
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};

    queue<Pos> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;

    while (!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        int wall = q.front().wall;

        if (y == n - 1 && x == m - 1)
        {
            answer = visited[y][x][wall];
            return;
        }

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || n <= ny || nx < 0 || m <= nx)
                continue;
            if (visited[ny][nx][wall])
                continue;

            if (grid[ny][nx] == 0)
            {
                visited[ny][nx][wall] = visited[y][x][wall] + 1;
                q.push({ny, nx, wall});
            }
            else if (wall == 0 && visited[ny][nx][1] == 0)
            {
                visited[ny][nx][1] = visited[y][x][wall] + 1;
                q.push({ny, nx, 1});
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < m; j++)
            grid[i][j] = str[j] - '0';
    }

    BFS();

    if (answer)
        cout << answer;
    else
        cout << -1;
    return 0;
}