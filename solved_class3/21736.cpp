#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, m, answer = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            char input;
            cin >> input;
            if (input == 'I')
            {
                q.push({i, j});
                visited[i][j] = true;
            }
            grid[i][j] = input;
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

            if (0 <= ny && ny < n && 0 <= nx && nx < m)
            {
                if (grid[ny][nx] != 'X' && visited[ny][nx] == false)
                {
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                    if (grid[ny][nx] != 'O')
                        answer++;
                }
            }
        }
    }
    if (answer == 0)
        cout << "TT";
    else
        cout << answer;
    return 0;
}