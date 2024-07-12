#include <iostream>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

int **arr;

void bfs(int y, int x, int n, int m)
{
    queue<tuple<int, int, int>> q;
    set<pair<int, int>> visit;
    int level = 0;
    q.push(make_tuple(y, x, level));
    arr[y][x] = 0;

    while (!q.empty())
    {
        // queue의 맨 앞 부분 가져오기
        auto front = q.front();
        auto pos = make_pair(get<0>(front), get<1>(front));
        level = get<2>(front);
        q.pop();

        // 방문 확인
        if (!visit.count(pos))
            visit.insert(pos);
        else
            continue;

        // 여기까지 거리가 얼마인지
        arr[pos.first][pos.second] = level;

        // 위쪽
        if (pos.first - 1 >= 0 && arr[pos.first - 1][pos.second] == 1)
            q.push(make_tuple(pos.first - 1, pos.second, level + 1));
        // 아래쪽
        if (pos.first + 1 < n && arr[pos.first + 1][pos.second] == 1)
            q.push(make_tuple(pos.first + 1, pos.second, level + 1));
        // 왼쪽
        if (pos.second - 1 >= 0 && arr[pos.first][pos.second - 1] == 1)
            q.push(make_tuple(pos.first, pos.second - 1, level + 1));
        // 오른쪽
        if (pos.second + 1 < m && arr[pos.first][pos.second + 1] == 1)
            q.push(make_tuple(pos.first, pos.second + 1, level + 1));
    }
}

int main()
{
    int n, m, targetX, targetY;
    cin >> n >> m;

    arr = new int *[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[m];

    // 배열 입력, 목표지점 좌표 저장
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                targetY = i;
                targetX = j;
            }
        }

    bfs(targetY, targetX, n, m);

    // 배열 출력중 목표의 상하좌우에 없는데 1인 경우 갈수 없는 지역이므로 -1 출력
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!(i == targetY - 1 && j == targetX) &&
                !(i == targetY + 1 && j == targetX) &&
                !(i == targetY && j == targetX - 1) &&
                !(i == targetY && j == targetX + 1) &&
                arr[i][j] == 1)
            {
                arr[i][j] = -1;
            }

            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}