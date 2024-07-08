#include <iostream>
#include <queue>
#include <set>
using namespace std;

int bfs(int x, int target)
{
    queue<pair<int, int>> q;
    set<int> visit;
    int frontQ, level = 0;

    q.push(make_pair(x, level));

    while (!q.empty())
    {
        frontQ = q.front().first;
        level = q.front().second;

        // 목표 도달
        if (frontQ == target)
            return q.front().second;

        q.pop();

        // 방문 체크
        if (!visit.count(frontQ))
            visit.insert(frontQ);
        else
            continue;

        // 방문한적 없고 100,000보다 작으면 push
        if (frontQ - 1 <= 100000)
            q.push(make_pair(frontQ - 1, level + 1));
        if (frontQ + 1 <= 100000)
            q.push(make_pair(frontQ + 1, level + 1));
        if (frontQ * 2 <= 100000)
            q.push(make_pair(frontQ * 2, level + 1));
    }
}

int main()
{
    int n, k, result;
    cin >> n >> k;
    cout << bfs(n, k);
    return 0;
}