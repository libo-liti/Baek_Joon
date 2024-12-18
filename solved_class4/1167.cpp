#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

vector<vector<pair<int, int>>> tree;
set<int> visited;
int long_dist;
int vertex;

void BFS(int start)
{
    queue<pair<int, int>> q;
    q.push({start, 0});

    while (!q.empty())
    {
        int v = q.front().first;
        int dist = q.front().second;
        q.pop();
        visited.insert(v);

        for (int i = 0; i < tree[v].size(); i++)
        {
            if (!visited.count(tree[v][i].first))
            {
                q.push({tree[v][i].first, dist + tree[v][i].second});
                if (dist + tree[v][i].second > long_dist)
                {
                    long_dist = dist + tree[v][i].second;
                    vertex = tree[v][i].first;
                }
            }
        }
    }
    visited.clear();
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int v1;
    cin >> v1;

    tree.resize(v1 + 1);

    for (int i = 1; i <= v1; i++)
    {
        int v;
        cin >> v;
        while (true)
        {
            int v2;
            cin >> v2;
            if (v2 == -1)
                break;
            int cost;
            cin >> cost;
            tree[v].push_back({v2, cost});
        }
    }
    BFS(1);
    long_dist = 0;
    BFS(vertex);
    cout << long_dist;
    return 0;
}