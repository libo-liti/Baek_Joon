#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int dy[6] = {0, 0, -1, 1, 0, 0};
    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dz[6] = {0, 0, 0, 0, -1, 1};
    int m, n, h, zero = 0, maxDay = 0;
    cin >> m >> n >> h;

    vector<vector<vector<int>>> grid(h, vector<vector<int>>(n, vector<int>(m, 0)));
    queue<tuple<int, int, int>> q;

    for (int z = 0; z < h; z++)
        for (int y = 0; y < n; y++)
            for (int x = 0; x < m; x++)
            {
                int input;
                cin >> input;
                grid[z][y][x] = input;

                if (input == 1)
                    q.push({z, y, x});
                else if (input == 0)
                    zero++;
            }

    if (zero == 0)
    {
        cout << 0;
        return 0;
    }

    while (!q.empty())
    {
        int z = get<0>(q.front());
        int y = get<1>(q.front());
        int x = get<2>(q.front());
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nz = z + dz[i];

            if (ny < 0 || n <= ny || nx < 0 || m <= nx || nz < 0 || h <= nz)
                continue;
            if (grid[nz][ny][nx] != 0)
                continue;

            maxDay = grid[nz][ny][nx] = grid[z][y][x] + 1;
            q.push({nz, ny, nx});
        }
    }
    for (int z = 0; z < h; z++)
        for (int y = 0; y < n; y++)
            for (int x = 0; x < m; x++)
                if (grid[z][y][x] == 0)
                {
                    cout << -1;
                    return 0;
                }
    cout << --maxDay;
    return 0;
}