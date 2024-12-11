#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;
vector<vector<pair<int, int>>> v;
vector<int> dist;

void Dijkstra(int start, int target, int n)
{
    vector<int> tem(n + 1, INF);
    tem[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int vertex = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (tem[vertex] < cost)
            continue;

        for (auto i : v[vertex])
        {
            int next_vertex = i.second;
            int next_cost = i.first;

            if (tem[next_vertex] > next_cost + cost)
            {
                pq.push({next_cost + cost, next_vertex});
                tem[next_vertex] = next_cost + cost;
            }
        }
    }
    if (start == target)
    {
        for (int i = 1; i <= n; i++)
            if (tem[i] != INF)
                dist[i] += tem[i];
    }
    else
    {
        if (tem[target] != INF)
            dist[start] += tem[target];
    }
}

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    v.resize(n + 1);
    dist.resize(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int s, e, cost;
        cin >> s >> e >> cost;
        v[s].push_back({cost, e});
    }
    for (int i = 1; i <= n; i++)
        Dijkstra(i, x, n);
    cout << *max_element(dist.begin(), dist.end());
    return 0;
}