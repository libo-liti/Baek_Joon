#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, nn = 0;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int BFS(vector<vector<int>> &grid, int startY, int startX)
{
    int num = 1;
    queue<pair<int, int>> q;
    q.push({startY, startX});
    grid[startY][startX] = 2;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || n <= ny || nx < 0 || n <= nx)
                continue;
            if (grid[ny][nx] != 1)
                continue;

            grid[ny][nx] = 2;
            num++;
            q.push({ny, nx});
        }
    }
    return num;
}

int main()
{
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < n; j++)
            grid[i][j] = input[j] - '0';
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)
            {
                answer.push_back(BFS(grid, i, j));
                nn++;
            }
    sort(answer.begin(), answer.end());
    cout << nn << "\n";
    for (auto i : answer)
        cout << i << "\n";
    return 0;
}