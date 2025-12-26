#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int n, m, _max, max_value;
bool visited[501][501];
vector<vector<int>> board;

void DFS(int y, int x, int depth, int sum)
{
    if (sum + (4 - depth) * max_value < _max)
        return;

    if (depth == 4)
    {
        _max = max(_max, sum);
        return;
    }

    for (int d = 0; d < 4; d++)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (ny < 0 || n <= ny || nx < 0 || m <= nx)
            continue;
        if (visited[ny][nx])
            continue;

        // ㅗ를 위한 특수 처리
        if (depth == 2)
        {
            visited[ny][nx] = true;
            DFS(y, x, depth + 1, sum + board[ny][nx]);
            visited[ny][nx] = false;
        }

        visited[ny][nx] = true;
        DFS(ny, nx, depth + 1, sum + board[ny][nx]);
        visited[ny][nx] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    board.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            max_value = max(max_value, board[i][j]);
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = true;
            DFS(i, j, 1, board[i][j]);
            visited[i][j] = false;
        }
    cout << _max;
    return 0;
}