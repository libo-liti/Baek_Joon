#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;
vector<vector<pair<int, int>>> v;
vector<vector<int>> answer;

void Dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    answer[start][start] = 0;

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        if (answer[start][vertex] < cost)
            continue;

        // 현재 점에서 갈 수 있는 곳
        for (auto i : v[vertex])
        {
            int next_vertex = i.second;
            int next_cost = i.first;

            // 최소비용 갱신
            if (cost + next_cost < answer[start][next_vertex])
            {
                answer[start][next_vertex] = cost + next_cost;
                pq.push({cost + next_cost, next_vertex});
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int **arr = new int *[n + 1];
    v.resize(n + 1);
    answer.resize(n + 1, vector<int>(n + 1, INF));

    // 배열 초기화
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = new int[n + 1];
        fill_n(arr[i], n + 1, INF);
    }

    // 입력값
    for (int i = 0; i < m; i++)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;

        if (arr[v1][v2] < cost)
            continue;

        arr[v1][v2] = cost;
        v[v1].push_back({cost, v2});
    }

    for (int i = 1; i < n + 1; i++)
        Dijkstra(i);

    // 결과 출력
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (answer[i][j] == INF)
                cout << 0 << " ";
            else
                cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    // 메모리 해제
    for (int i = 0; i < n + 1; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}