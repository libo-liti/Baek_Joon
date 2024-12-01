#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;

vector<vector<pair<int, int>>> graph;
vector<int> answer;
int v, e, s;

void dijkstra(int start)
{
    // 우선순위 큐
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 시작점
    answer[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        // 현재 최소거리로 갈 수 있는 곳
        int cost = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        // 지금 비용이 최소가 아닐때
        if (answer[vertex] < cost)
            continue;

        // 현재 점에서 갈 수 있는 점
        for (auto edge : graph[vertex])
        {
            int next_cost = edge.first;
            int next_vertex = edge.second;

            // 갈 수 있는 점이 최소거리일때
            if (answer[next_vertex] > cost + next_cost)
            {
                answer[next_vertex] = cost + next_cost;
                pq.push({answer[next_vertex], next_vertex});
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    // 그래프 초기화
    cin >> v >> e >> s;
    graph.resize(v + 1);
    answer.resize(v + 1, INF);

    // 그래프 입력
    for (int i = 0; i < e; i++)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        graph[v1].push_back({cost, v2});
    }
    dijkstra(s);

    // 최소거리 출력
    for (int i = 1; i < v + 1; i++)
        if (answer[i] == INF)
            cout << "INF" << "\n";
        else
            cout << answer[i] << "\n";

    return 0;
}