#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> grahp;
set<int> visited;

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty())
    {
        int vertex = q.front();
        cout << vertex << " ";
        q.pop();

        for (int i = 0; i < grahp[vertex].size(); i++)
        {
            int next_v = grahp[vertex][i];
            if (!visited.count(next_v))
            {
                visited.insert(next_v);
                q.push(next_v);
            }
        }
    }
    visited.clear();
    return;
}

void DFS(int vertex)
{
    cout << vertex << " ";
    visited.insert(vertex);
    for (int i = 0; i < grahp[vertex].size(); i++)
    {
        int next_v = grahp[vertex][i];
        if (!visited.count(next_v))
            DFS(next_v);
    }
    return;
}

int main()
{
    int vertex, edge, start;
    cin >> vertex >> edge >> start;

    grahp.resize(vertex + 1);
    for (int i = 0; i < edge; i++)
    {
        int s, e;
        cin >> s >> e;
        grahp[s].push_back(e);
        grahp[e].push_back(s);
    }

    for (int i = 0; i < grahp.size(); i++)
        sort(grahp[i].begin(), grahp[i].end());

    DFS(start);
    visited.clear();
    cout << "\n";
    BFS(start);

    return 0;
}