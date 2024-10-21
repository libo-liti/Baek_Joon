#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int Max = 100001;
int arr[Max];
queue<int> q;

void BFS(int a, int b)
{
    // a >= b 일때는 -1로만 갈 수 있음
    if (a >= b)
    {
        cout << a - b;
        return;
    }

    int frontQ;
    q.push(a);

    while (!q.empty())
    {
        frontQ = q.front();
        q.pop();

        // 목적지 도착
        if (frontQ == b)
        {
            cout << arr[frontQ];
            return;
        }

        for (auto next : {frontQ * 2, frontQ - 1, frontQ + 1})
        {
            // 인덱스 범위 체크
            if (next < 0 || next >= Max)
                continue;

            if (arr[next] == -1)
            {
                if (next == frontQ * 2)
                    arr[next] = arr[frontQ];
                else
                    arr[next] = arr[frontQ] + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    int a, b;
    cin >> a >> b;

    fill(arr, arr + Max, -1);
    arr[a] = 0;

    BFS(a, b);
    return 0;
}