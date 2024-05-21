#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

void bfs(vector<vector<int>> &v, int hh, int ww)
{
    int h, w;
    queue<tuple<int, int>> que;
    tuple<int, int> t(hh, ww);
    que.push(t);

    while (!que.empty())
    {
        h = get<0>(que.front());
        w = get<1>(que.front());
        que.pop();

        if (w - 1 >= 0)
        {
            if (v[h][w - 1] == 1)
            {
                v[h][w - 1] = 0;
                t = {h, w - 1};
                que.push(t);
            }
        }
        if (w + 1 < v[0].size())
        {
            if (v[h][w + 1] == 1)
            {
                v[h][w + 1] = 0;
                t = {h, w + 1};
                que.push(t);
            }
        }
        if (h + 1 < v.size())
        {
            if (v[h + 1][w] == 1)
            {
                v[h + 1][w] = 0;
                t = {h + 1, w};
                que.push(t);
            }
        }
        if (h - 1 >= 0)
        {
            if (v[h - 1][w] == 1)
            {
                v[h - 1][w] = 0;
                t = {h - 1, w};
                que.push(t);
            }
        }
    }

    return;
}

int main()
{
    cin.tie(0)->sync_with_stdio;

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int width, height, n, cnt = 0;
        cin >> width >> height >> n;
        vector<vector<int>> v(height, vector<int>(width, 0));

        for (int i = 0; i < n; i++)
        {
            int w, h;
            cin >> w >> h;
            v[h][w] = 1;
        }

        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                if (v[i][j])
                {
                    v[i][j] = 0;
                    bfs(v, i, j);
                    cnt++;
                }
        cout << cnt << "\n";
    }
    return 0;
}