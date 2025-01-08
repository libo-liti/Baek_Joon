#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>
using namespace std;
const int INF = INT_MAX;

vector<vector<pair<int, int>>> graph;
int sum;

void Prim(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    set<int> visited;
    pq.push({0, start});

    while (!pq.empty())
    {
        int vertex = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (visited.count(vertex))
            continue;
        visited.insert(vertex);
        sum += cost;

        for (int i = 0; i < graph[vertex].size(); i++)
        {
            int next_v = graph[vertex][i].first;
            int next_c = graph[vertex][i].second;

            if (visited.count(next_v))
                continue;

            pq.push({next_c, next_v});
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    graph.resize(v + 1);

    for (int i = 0; i < e; i++)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        graph[v1].push_back({v2, cost});
        graph[v2].push_back({v1, cost});
    }

    Prim(1);
    cout << sum;
    return 0;
}