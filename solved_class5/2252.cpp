#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> answer;
vector<vector<int>> v;
vector<int> inDegree;
int n, m;

void TopologySort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (inDegree[i] == 0)
            q.push(i);

    for (int i = 1; i <= n; i++)
    {
        if (q.empty())
            return;

        int node = q.front();
        q.pop();
        answer.push_back(node);

        for (int i = 0; i < v[node].size(); i++)
        {
            if (--inDegree[v[node][i]] == 0)
                q.push(v[node][i]);
        }
    }
}

int main()
{
    cin >> n >> m;
    v.resize(n + 1);
    inDegree.resize(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        inDegree[b]++;
    }
    TopologySort();
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    return 0;
}