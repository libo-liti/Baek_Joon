#include <iostream>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

int **arr;
queue<tuple<int, int, int>> q;
set<pair<int, int>> visit;
int maxLevel;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int height, int width)
{
    while (!q.empty())
    {
        // 큐의 맨 앞
        auto frontQ = q.front();
        auto pos = make_pair(get<0>(frontQ), get<1>(frontQ));
        int level = get<2>(frontQ);
        q.pop();

        // 방문체크
        if (!visit.count(pos))
            visit.insert(pos);
        else
            continue;

        // 4방향 검사
        for (int i = 0; i < 4; i++)
        {
            int _y, _x;
            _y = pos.first + dy[i];
            _x = pos.second + dx[i];

            if ((0 <= _y && _y < height) && (0 <= _x && _x < width) && !visit.count(make_pair(_y, _x)) && arr[_y][_x] == 0)
            {
                q.push(make_tuple(_y, _x, level + 1));
                if (maxLevel < level + 1)
                    maxLevel = level + 1;
                arr[_y][_x] = 1;
            }
        }
    }
}
// 토마토가 안 익은 곳이 있는지 체크
int PossibleCheck(int n, int m)
{
    int minus = 0;

    // 못 가는 곳 체크
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 0)
                return -1;

    // 전부 -1인 경우
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == -1)
                minus++;
    if (minus == n * m)
        return -1;

    // 전부 익는 경우
    return maxLevel;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int m, n, PosX, PosY;
    cin >> m >> n;

    // 토마토 창고
    arr = new int *[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[m];

    // 토마토 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];

            // 익은 토마토가 있는곳 체크
            if (arr[i][j] == 1)
                q.push(make_tuple(i, j, 0));
        }
    bfs(n, m);
    cout << PossibleCheck(n, m);
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}