#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int answer = 0;
    int row = maps.size();
    int col = maps[0].size();
    int visited[100][100]{};

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || row <= ny || nx < 0 || col <= nx)
                continue;
            if (maps[ny][nx] != 1)
                continue;
            if (visited[ny][nx] != 0)
                continue;

            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
    answer = visited[row - 1][col - 1] == 0 ? -1 : visited[row - 1][col - 1];
    return answer;
}

int main()
{
    vector<vector<int>> maps = {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1}};

    cout << solution(maps);
    return 0;
}