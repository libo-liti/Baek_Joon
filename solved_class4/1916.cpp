#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);

    int n, m, start, end;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int *distance = new int[n + 1];
    fill(distance, distance + n + 1, 1000000000);

    for (int i = 0; i < m; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].push_back({b, cost});
    }
    cin >> start >> end;
    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (distance[node] < dist)
            continue;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int nextNode = graph[node][i].first;
            int cost = graph[node][i].second + dist;

            if (cost < distance[nextNode])
            {
                pq.push({cost, nextNode});
                distance[nextNode] = cost;
            }
        }
    }
    cout << distance[end];
    delete[] distance;
    return 0;
}