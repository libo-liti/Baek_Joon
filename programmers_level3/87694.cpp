#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int answer = 0;
    vector<vector<int>> grid(102, vector<int>(102, 0));
    vector<vector<int>> dist(102, vector<int>(102, 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < rectangle.size(); i++)
    {
        int x1, y1, x2, y2;
        x1 = rectangle[i][0] * 2;
        y1 = rectangle[i][1] * 2;
        x2 = rectangle[i][2] * 2;
        y2 = rectangle[i][3] * 2;

        for (int row = y1; row <= y2; row++)
        {
            for (int col = x1; col <= x2; col++)
            {
                if (grid[row][col] == 1)
                    continue;

                if (row == y1 || row == y2 || col == x1 || col == x2)
                    grid[row][col] = 2;
                else
                    grid[row][col] = 1;
            }
        }
    }

    dist[characterY * 2][characterX * 2] = 1;
    q.push({characterY * 2, characterX * 2});

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        if (y == itemY * 2 && x == itemX * 2)
            return (dist[y][x] - 1) / 2;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nx < 0 || 100 < nx || ny < 0 || 100 < ny)
                continue;
            if (dist[ny][nx] != 0 || grid[ny][nx] != 2)
                continue;

            q.push({ny, nx});
            dist[ny][nx] = dist[y][x] + 1;
        }
    }

    return answer;
}