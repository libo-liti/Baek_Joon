#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int sum;

int Search(vector<int> &buliding, vector<vector<int>> &rule, int target)
{
    queue<int> q;
    vector<int> dist(buliding.size() + 1, -1);
    dist[target] = buliding[target];
    q.push(target);

    while (!q.empty())
    {
        int node = q.front();
        int cost = buliding[node];
        q.pop();

        for (int i = 0; i < rule[node].size(); i++)
        {
            int next_node = rule[node][i];
            int next_cost = dist[node] + buliding[next_node];

            if (dist[next_node] < next_cost)
            {
                dist[next_node] = next_cost;
                q.push(rule[node][i]);
            }
        }
    }
    return *max_element(dist.begin(), dist.end());
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n, k, target;
        cin >> n >> k;
        vector<int> buliding(n + 1, 0);
        vector<vector<int>> rule(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> buliding[i];
        for (int i = 0; i < k; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            rule[v2].push_back(v1);
        }

        cin >> target;
        cout << Search(buliding, rule, target) << "\n";
    }
    return 0;
}