#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> v;
vector<int> parent;
set<int> visited;

void dfs(int node)
{
    for (int i = 0; i < v[node].size(); i++)
    {
        if (!visited.count(v[node][i]))
        {
            visited.insert(v[node][i]);
            parent[v[node][i]] = node;
            dfs(v[node][i]);
        }
    }
}

int main()
{
    int n, node1, node2;
    cin >> n;
    v.resize(n + 1);
    parent.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> node1 >> node2;
        v[node1].push_back(node2);
        v[node2].push_back(node1);
    }
    visited.insert(1);
    dfs(1);

    for (int i = 2; i <= n; i++)
        cout << parent[i] << "\n";
    return 0;
}